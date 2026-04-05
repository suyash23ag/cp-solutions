# 🤖 Auto-Commit Solutions

Automatically fetches your accepted submissions from **LeetCode** and **Codeforces** and commits them to GitHub — every 10 minutes via a cron job.

---

## 📁 Project Structure

```
auto-commit-solutions/
│
├── main.py                  ← Run this (entry point)
├── leetcode_fetcher.py      ← Fetches LeetCode solutions via GraphQL API
├── codeforces_fetcher.py    ← Fetches Codeforces solutions via REST API + scraping
├── git_committer.py         ← Runs git add / commit / push
│
├── config.json              ← Your credentials (NEVER commit this!)
├── requirements.txt
│
├── solutions/
│   ├── leetcode/
│   │   └── two-sum/
│   │       └── solution.py  ← auto-saved with problem info in header
│   └── codeforces/
│       └── 1234_A_WaterMelon/
│           └── solution.cpp
│
└── logs/
    ├── leetcode.log
    ├── codeforces.log
    ├── git.log
    ├── seen_leetcode.json   ← tracks which submissions were already committed
    └── seen_codeforces.json
```

---

## ⚙️ Setup (Step by Step)

### Step 1 — Clone / init your GitHub repo

```bash
git init
git remote add origin https://github.com/YOUR_USERNAME/cp-solutions.git
git branch -M main
```

### Step 2 — Install dependencies

```bash
pip install -r requirements.txt
```

### Step 3 — Fill in config.json

#### For LeetCode:
1. Go to [leetcode.com](https://leetcode.com) and log in
2. Open **DevTools** (F12) → **Application** tab → **Cookies** → `https://leetcode.com`
3. Copy the value of the cookie named `LEETCODE_SESSION`
4. Paste it in `config.json`

#### For Codeforces:
1. Just put your Codeforces handle (username) in `config.json`
2. The `jsessionid` field is optional — only needed for private/gym contests

```json
{
  "leetcode": {
    "username": "john_doe",
    "session_cookie": "eyJ0eXAiOiJ..."
  },
  "codeforces": {
    "handle": "john_doe",
    "jsessionid": ""
  }
}
```

> ⚠️ **IMPORTANT**: Add `config.json` to your `.gitignore` — never push your session cookie!

### Step 4 — Add config.json to .gitignore

```bash
echo "config.json" >> .gitignore
echo "logs/" >> .gitignore
git add .gitignore
git commit -m "Initial commit"
git push -u origin main
```

### Step 5 — Test it manually

```bash
python main.py                   # both platforms
python main.py --platform lc     # only LeetCode
python main.py --platform cf     # only Codeforces
python main.py --no-push         # save files but don't push
```

---

## ⏰ Setting Up the Cron Job (runs every 10 minutes)

```bash
crontab -e
```

Add this line (update the path to your actual project path):

```
*/10 * * * * cd /home/youruser/auto-commit-solutions && python main.py >> logs/cron.log 2>&1
```

To verify it's set:
```bash
crontab -l
```

---

## 🔍 What Each File Does (with your roadmap knowledge)

| File | Concepts used |
|------|--------------|
| `leetcode_fetcher.py` | `requests`, JSON, file handling, logging, exceptions |
| `codeforces_fetcher.py` | `requests`, REST API, html.parser, logging |
| `git_committer.py` | `subprocess`, os, exceptions |
| `main.py` | `argparse`, modules, imports |
| `config.json` | JSON config pattern |
| cron | Linux cron basics |

---

## 📝 Example Output

```
=======================================================
  🤖 Auto-Commit Solutions — 2025-03-15 14:30:01
=======================================================

🔍 Checking LeetCode for new accepted submissions...
  🆕 New submission found: Two Sum (python3)
  ✅ Saved: solutions/leetcode/two-sum/solution.py

🔍 Checking Codeforces for new accepted submissions...
  🆕 New AC found: Watermelon (Contest 4)
  ✅ Saved: solutions/codeforces/4_A_Watermelon/solution.py

📦 Committing 2 new solution(s) to Git...
  ✅ Committed: ✅ [2025-03-15] Added 2 solutions (leetcode, codeforces)
  🚀 Pushed to GitHub!

=======================================================
```

---

## 🚀 Possible Enhancements (Phase 5 ideas)

- Add a `--stats` flag that prints your solve count per difficulty/tag
- Build a Flask dashboard to browse your solutions (Phase 3!)
- Add email/Telegram notification when a new solution is committed
- Track your rating progression on Codeforces over time
