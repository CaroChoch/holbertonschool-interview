#!/usr/bin/python3
""" Count it! """
import requests

def count_words(subreddit, word_list):
    """ Count it! """
    # Define the URL for the Reddit API endpoint
    url = 'https://www.reddit.com/r/{}/hot.json'.format(subreddit)
    
    # Define the headers for the request to include a User-Agent
    headers = {'User-Agent': 'Python/requests:APIproject:0.0.1 (by /u/veeteeran)'}
    
    # Make a GET request to the Reddit API
    response = requests.get(url, headers=headers, allow_redirects=False)
    
    # Check if the response status is not OK (200)
    if response.status_code != 200:
        print()
        return
    
    # Parse the JSON response
    response = response.json()
    data = response.get('data')
    children = data.get('children')
    
    # Initialize a dictionary to count the occurrences of each word
    word_dict = {}
    for word in word_list:
        word_dict[word] = 0
    
    # Iterate over each post in the response
    for child in children:
        # Get the title of the post and split it into words
        title = child.get('data').get('title').lower().split()
        
        # Count the occurrences of each word in the title
        for i in title:
            if i in word_dict:
                word_dict[i] += 1
    
    # Sort the dictionary by the count of each word in descending order
    sorted_dict = sorted(word_dict.items(), key=lambda x: x[1], reverse=True)
    
    # Print the words and their counts
    for key, value in sorted_dict:
        if value != 0:
            print('{}: {}'.format(key, value))
