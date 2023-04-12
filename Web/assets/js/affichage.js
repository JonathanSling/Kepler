//Fonction qui permet d'organiser les éléments HTML pour le chargement d'un nouveau JSON
function htmlSet(key) {
    //suppression des éléments HTML pour faire place aux nouveaux
    if (ul.hasChildNodes()){
        let li2 = ul2.querySelectorAll("li");
        let button = li2[li2.length-1].querySelectorAll("button")[0];
        button.removeEventListener("click", calculAlign);
        let li = ul.querySelectorAll("li");
        li2 = ul2.querySelectorAll("li");
        for(let i = 0; i < li.length; i++){
            ul.removeChild(li[i]);
            ul2.removeChild(li2[i]);
        }
        ul2.removeChild(ul2.querySelectorAll("li")[0]);
        ul2.removeChild(ul2.querySelectorAll("p")[1]);
    }

    //boucle for qui effectue les actions pour chaque planete du json
    for (i in key) {
        //création des éléments HTML pour les toggle planetes et affichage des vitesse quadratiques
        let li = document.createElement("li");
        let p = document.createElement("p");
        let pspeed = document.createElement("p");
        let button = document.createElement("button");
        p.innerHTML = key[i];
        button.innerHTML = ("Toggle");
        li.appendChild(p)
        li.appendChild(button);
        li.appendChild(pspeed);
        ul.appendChild(li);

        //création des éléments HTML pour le menu des alignements
        let li2 = document.createElement("li");
        let input = document.createElement("input");
        let label = document.createElement("label");
        input.type = ("checkbox");
        input.id = key[i];
        label.htmlFor = key[i];
        label.innerHTML = key[i];
        li2.appendChild(input);
        li2.appendChild(label);
        ul2.appendChild(li2);

        //gestion du bouton toggle de la planète
        let liButton = ul.querySelectorAll("li")[i];
        liButton.getElementsByTagName("button")[0].addEventListener("click", function func() {
            liButton.classList.toggle("active");
        });
    }

    //ajout bouton calcul alignement
    let li2 = document.createElement("li");
    let button = document.createElement("button");
    button.innerHTML = "Calcul";
    li2.appendChild(button);
    ul2.appendChild(li2);

    //ajout du texte "alignement planetes dans..."
    let text = document.createElement("p");
    text.innerHTML = "Alignement des planetes  dans : t";
    text.style.opacity = 0
    ul2.appendChild(text);

    //gestion affichage vitesse quadratique
    let li = ul.querySelectorAll("li");
    for(let i = 0; i < li.length; i++){
        li[i].querySelectorAll("p")[1].innerHTML = "Vitesse quadratique : 00000" + " m/s";
    }

    //gestion du bouton de calcul d'alignement
    li2 = ul2.querySelectorAll("li");
    button = li2[li2.length-1].querySelectorAll("button")[0];
    button.addEventListener("click", calculAlign);
}

//Fonction qui change le css quand un astre est activé/désactivé
function cssSet() {
    //on séléctionne les deux li associés au astres
    li = ul.querySelectorAll("li");
    li2 = document.getElementById("align").querySelectorAll("li");

    for (let i = 0; i < li.length; i++) { //pour toutes les planètes
        if (li[i].classList.contains("active")) { //planète activé on affiche la vitesse, on change la couleur, et l'astre dans le canvas
            li[i].querySelectorAll("p")[1].innerHTML = "Vitesse quadratique : " + speed[i][position] + " m/s";
            astre(traj[i], color[i]);
            li[i].querySelectorAll("p")[0].style.color = color[i];
            li2[i].querySelectorAll("label")[0].style.color = color[i];
            li[i].querySelectorAll("p")[1].style.opacity = 1;
        } else { //sinon on enlève la couleur et on cache la vitesse
            li[i].querySelectorAll("p")[0].style.color = "white";
            li2[i].querySelectorAll("label")[0].style.color = "white";
            li[i].querySelectorAll("p")[1].style.opacity = 0;
        }
    }
}

//Fonction qui affiche le texte de présentation du projet sur le canvas
function presentationText() {
    let presentation = "Cette page web génère la trajectoire d’une ou de plusieurs planètes à l’aide d’un code C. Le code C exporte les données dans un fichier json qui permet à la page web de modéliser la ou les trajectoires de planètes.";

    //fonctions relatives à p5.js
    background(0);
    stroke("black");
    fill("white");
    textSize(32);
    textWrap(WORD);
    textAlign(CENTER, CENTER)
    text(presentation, 0, 200, 800);
}

//fonction qui affiche les étoiles sur le canvas
function star() {
    stroke('white');
    for (let j = 0; j < stars.length; j++) {
        point(stars[j].x, stars[j].y); //on affiche toutes les étoiles créées précédemment
    }
}

//fonction qui affiche l'alignement des planètes
function alignement(){
    let text = ul2.querySelectorAll("p")[1]; //on sélectionne le dernier texte dans le ul alignement
    if (aligncalc){
        text.style.opacity = 1;
        text.innerHTML = "Alignement des planetes  dans : t" + alignPos();
    }else{
        text.style.opacity = 0;
    }
}

//Fonction qui affiche avec p5.js la trajectoire de la planète ainsi que la planète
function astre(Tdata, color) {
    scale = document.getElementById("scale").value;

    //trajectoire
    stroke(color);
    noFill();
    beginShape();
    for (let j = 0; j < Tdata.length - 1; j += 20) {
        curveVertex(Tdata[j][scale][0], Tdata[j][scale][1]);
    }
    endShape();

    //astre           
    fill(color);
    strokeWeight(5);
    point(Tdata[position][scale][0], Tdata[position][scale][1]);
    strokeWeight(1);
}