let position = 1, scale = 11, vitessepos = 1; //variables globales de positionnement
let color = ['#FF0000', '#0000FF', '#00FF00', '#00FFFF', '#FFFF00', '#FF00FF', '#FFA500', '#9ACD32']; //liste couleurs pour générer max 8 planètes
let tminus = [], stars = []; //
let raw = [], traj = [], speed = []; //array venant du json (raw = data brute, traj = data à l'echelle, speed = vitesse quadratique)
let started = false, aligncalc = false; //variables bool (started bloc la fonction draw et aligncalc permet d'afficher ou non le texte d'alignement des planètes)
let ul = document.getElementById("Planetes"); //container planètes
let ul2 = document.getElementById("align"); //menu alignement

//Fonction relative à p5.js, s'execute une fois
function setup() {
    started = false;
    createCanvas(800, 400);
    li = ul.querySelectorAll("li");
    for(let i = 0; i<li.length; i++){
        li[i].querySelectorAll("p")[1].innerHTML = "Vitesse quadratique : 00000" + " m/s";
    }    
    generateStar();
    started = true;
}

//Fonction relative à p5.js s'execute en boucle
function draw() {
    if(started){
        if (classEmpty(li)){ //si aucune planète n'est activée on affiche le texte de présentation dans le canvas
            position = 1;

            presentationText();
            cssSet();
        }else{ //sinon on affiche les astres
            
            li = ul.querySelectorAll("li");

            background(0);

            star();

            //soleil
            stroke(255, 255, 0);
            strokeWeight(scale);
            point(400, 200);
            strokeWeight(1);
            
            cssSet();

            alignement();
            
            vitessepos = parseInt(document.getElementById("speed").value, 10); //on met en int la string renvoyé par le slider de vitesse html
            position += vitessepos;
            
            if (position > raw[0].length)
                position = 1;
        }
    }
}