# Wellness Journal
## Overview
The Wellness Journal is a web application that allows users to journal their feelings daily. It provides a daily quote for inspiration and stores user entries for future reference. This application is built using Flask for the web interface and a C program for handling the backend logic.
## Features
- Daily inspirational quote
- Form to enter the date and feelings
- Display of previous diary entries
- Persistent storage of entries
## Technologies Used
- Python
- Flask
- C
- HTML/CSS
- JavaScript
## Setup and Installation
### Prerequisites
- Python 3.x
- GCC (for compiling the C program)
- Flask
### Steps
1. **Clone the Repository**:
    ```sh
    git clone https://github.com/nishatolay/WellnessJournal.git
    cd WellnessJournal
    ```
2. **Compile the C Program**:
    ```sh
    gcc -o mental_health_project mental_health_project.c
    chmod +x mental_health_project
    ```
3. **Install Python Dependencies**:
    ```sh
    pip install Flask
    ```
4. **Set the Flask App Environment Variable**:
    On macOS/Linux: 
    ```sh
    export FLASK_APP=app.py
    ```
    On Windows (Command Prompt):
    ```sh
    set FLASK_APP=app.py
    ```
    On Windows (PowerShell):
    ```sh
    $env:FLASK_APP = "app.py"```
5. **Run the Flask Application**:
    ```sh
    flask run
    ```
6. **Access the Web Application**:
    Open your web browser and go to `http://localhost:8080`.
## Usage
1. **New Diary Entry**:
    - On the homepage, you will see a form to enter today's date and how you are feeling.
    - Fill in the details and click the "Submit" button.
    - A daily inspirational quote will be displayed along with the form.
2. **View Previous Entries**:
    - Click on the "Previous Entries" tab to see all past diary entries.
    - Entries are displayed with the date and the feelings recorded on that day.

## Files
- **app.py**: Flask application file
- **Diary.txt**: File where diary entries are stored
- **mental_health_project.c**: C program for handling diary entry logic
- **mental_health_project**: Compiled binary of the C program
- **static**: Directory for static files (CSS, JS)
- **templates**: Directory for HTML templates
  
## Acknowledgements
- Quotes are sourced from various public figures.
- The base C code and Flask application were developed by Nishat Olayiwola.

## Contact
For any questions or feedback, please contact Nishat Olayiwola at [nolay@sas.upenn.edu](mailto:nolay@sas.upenn.edu).
