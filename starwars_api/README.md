# <p align="center">Starwars Api</p>


## 📝 Description

This project is developing an API to access information from characters from Star Wars movies. It uses the public Star Wars API to retrieve character data based on the movie identifier given as an argument. This project is particularly useful for Star Wars developers and fans wishing to explore in a programmed way the details of the different characters in the movies.

The project is structured in such a way as to facilitate use and expansion by other developers. The main script, `0-starwars_characters.js`, displays the names of the characters of a specified movie, in the order they appear in the list of characters of the endpoint `/films/` of the Star Wars API.

## 📚 Resources

- [Documentation of Node.js](https://nodejs.org/en/docs/)
- [Star Wars API](https://swapi-api.hbtn.io)
- [npm semistandard package](https://www.npmjs.com/package/semistandard)
- [npm request package](https://www.npmjs.com/package/request)
- [Airbnb JavaScript style guides](https://github.com/airbnb/javascript)

## 🛠️ Technologies and Tools Used

- **Node.js**: Used to write the API access script because of its ease of use for network requests and its wide adoption in the development community.
- **npm (Node Package Manager)**: Used to manage packages that facilitate HTTP requests.
- **Semi-standard**: Used to ensure compliance with coding conventions and code quality.

## 📋 Prerequisite

- Node.js (version 10.14.x)
- npm installed globally

## 🚀 Installation and Configuration

1. **Installation of Node.js**:

```bash
curl -sL https://deb.nodesource.com/setup_10.x | sudo -E bash -

sudo apt-get install -y nodejs
```

2. **Installation of semi-standard**:
  
```bash
sudo npm install semistandard --global
```

3. **Installation of request**:

```bash
sudo npm install request --global

export NODE_PATH=/usr/lib/node_modules
```

4. **Clone the repository**:

```bash
https://github.com/CaroChoch/holbertonschool-interview.git
```

5. **Move to the working directory**:

```bash
cd starwars_api
```

## 💡 Use

Run the script by providing the movie ID as an argument to display the characters of this movie:

```bash
./0-starwars_characters.js 3
```

Result:

```bash
Luke Skywalker
C-3PO
R2-D2
Darth Vader
Leia Organa
Obi-Wan Kenobi
Chewbacca
Han Solo
Jabba Desilijic Tiure
Wedge Antilles
Yoda
Palpatine
Boba Fett
Lando Calrissian
Ackbar
Mon Mothma
Arvel Crynyd
Wicket Systri Warrick
Nien Nunb
Bib Fortuna
```

## ✨ Main Features

- **Character display**: The script displays the list of characters in a specified movie, in the order of their appearance.
- **Interface with the Star Wars API**: Uses the external API to extract the necessary data.

## 📝 List of Tasks

| Number | Task | Description |
|--------|-----------------------------------|-----------------------------------------------------------------------------------------|
| 0 | [**Star Wars Characters**](https://   a remplir) | Write a script that displays all the characters of a Star Wars movie. |

## 📬 Contact
- Profil LinkedIn : [Caroline CHOCHOY](https://www.linkedin.com/in/caroline-chochoy62/)
