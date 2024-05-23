#!/usr/bin/python3
""" Count it! """
import requests


def count_words(subreddit, word_list):
    """ Count it! """
    # Define the URL for the Reddit API endpoint
    # Define the URL for the Reddit API endpoint, formatted with the subreddit name
url = 'https://www.reddit.com/r/{}/hot.json'.format(subreddit)

# Define the headers for the request to include a User-Agent
headers = {'User-Agent': 'Python/requests:APIproject:0.0.1 (by /u/veeteeran)'}

# Make a GET request to the Reddit API
response = requests.get(url, headers=headers, allow_redirects=False)

# Check if the response status is not OK (200)
if response.status_code != 200:
    return None

# Parse the JSON response to get the list of hot posts
hot_posts = response.json().get('data').get('children')

# Extract the titles of all hot posts
hot_titles = [post.get('data').get('title') for post in hot_posts]

# Initialize a dictionary to count the occurrences of each word
word_count = {}
for word in word_list:
    word_count[word] = 0
    # Count occurrences of the word in each title, case-insensitive
    for title in hot_titles:
        word_count[word] += len(re.findall(r'\b{}\b'.format(word), title, re.IGNORECASE))

# Sort the word list by count (descending) and alphabetically (ascending) in case of a tie
for word in sorted(word_list, key=lambda x: (-word_count[x], x)):
    # Print the word and its count if the count is greater than 0
    if word_count[word] > 0:
        print('{}: {}'.format(word.lower(), word_count[word]))
