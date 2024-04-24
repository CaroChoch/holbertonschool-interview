#!/usr/bin/node

/*
script that prints all characters of a Star Wars movie:
The first positional argument passed is the Movie ID - example: 3 = “Return of the Jedi”
Display one character name by line in the same order as the characters list in the /films/ endpoint
You must use the Star wars API
You must use the request module
*/

const request = require('request');
const movieId = process.argv[2];
const url = `https://swapi-api.hbtn.io/api/films/${movieId}`;

request(url, function (error, response, body) {
    const characters = JSON.parse(body).characters;
    let count = 0;

    function printNextCharacter() {
        if (count < characters.length) {
            request(characters[count], function (error, response, body) {
                console.log(JSON.parse(body).name);
                count++;
                printNextCharacter();
            });
        }
    }

    printNextCharacter();
});
