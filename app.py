from flask import Flask, request, render_template
import subprocess
import os
import random

app = Flask(__name__)

#Diary Text File
diary_file_path = 'Diary.txt'
if not os.path.exists(diary_file_path):
    with open(diary_file_path, 'w') as f:
        f.write("Date|Feeling\n")

#Function that will grab the random quote
def get_daily_quote():
    quotes = [
        "'I found that with depression, one of the most important things you can realize is that you’re not alone. You’re not the first to go through it, you’re not gonna be the last to go through it,' — Dwayne The Rock Johnson",
        "‘The advice I’d give to somebody that’s silently struggling is, you don’t have to live that way. You don’t have to struggle in silence. You can be un-silent. You can live well with a mental health condition, as long as you open up to somebody about it, because it’s really important you share your experience with people so that you can get the help that you need.’ — Demi Lovato",
        "‘Put yourself at the top of your to-do list every single day and the rest will fall into place.’",
        "‘You are not your illness. You have an individual story to tell. You have a name, a history, a personality. Staying yourself is part of the battle.’",
        "‘Mental health needs a great deal of attention. It’s the final taboo and it needs to be faced and dealt with.’ — Adam Ant"
    ]
    return random.choice(quotes)

#Function to load previous entries
def load_entries():
    entries = []
    with open(diary_file_path, 'r') as f:
        for line in f.readlines()[1:]:
            date, feeling = line.strip().split("|")
            entries.append({"date": date, "feeling": feeling})
    return entries

@app.route('/', methods=['GET', 'POST'])
def index():
    if request.method == 'POST':
        date = request.form['date']
        feeling = request.form['feeling']
        try:
            result = subprocess.run(['./mental_health_project', date, feeling], text=True, capture_output=True, check=True, timeout=10)
            output = result.stdout
        except subprocess.TimeoutExpired as e:
            output = "The operation timed out."
        except subprocess.CalledProcessError as e:
            output = f"An error occurred: {e}"
        except Exception as e:
            output = f"Unexpected error: {e}"

    quote = get_daily_quote()
    entries = load_entries()
    return render_template('index.html', quote=quote, entries=entries)

if __name__ == '__main__':
    if not os.access('./mental_health_project', os.X_OK):
        os.chmod('./mental_health_project', 0o775)
    app.run(host='0.0.0.0', port=8080, debug=True)