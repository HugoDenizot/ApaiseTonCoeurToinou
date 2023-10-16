import { Component, OnInit } from '@angular/core';
import { AfterViewInit } from '@angular/core';
import { HttpClient, HttpParams, HttpHeaders } from '@angular/common/http';
import { ActivatedRoute } from '@angular/router';


@Component({
  selector: 'app-game',
  templateUrl: './game.component.html',
  styleUrls: ['./game.component.css']
})
export class GameComponent implements OnInit {
  constructor(private http: HttpClient,private route: ActivatedRoute) {
    this.id_player=this.route.snapshot.queryParams['id_player'];
    this.id_session=this.route.snapshot.queryParams['id_session'];
    this.nom=this.route.snapshot.queryParams['nom'];
   }
  id_player:number;
  id_session:number;
  nom:string;
  nomJoueurTour:string="";
  personnalBoard: any[][] = [];
  shotBoard:any[][]=[];
  responses:Object[]=[];
  data:string="";
  ngOnInit() {
    let apiUrl = 'https://localhost:7080/';
    let params = new HttpParams().set('id', this.id_player);

    setInterval(() => {
      this.http.get<any>(`https://localhost:7080/api/GameArea/GetSession/${this.id_session}`).subscribe((data) => {
        if (this.data !== data) {
          this.data = data;
          location.reload();
        }
      });
    }, 10000);

    this.http.get<any>(`https://localhost:7080/api/GameArea/GetSession/${this.id_session}`).subscribe(
      (data)=>{
        
        console.log(data);
        this.nomJoueurTour=data.nameJoueurEnCours;
        console.log(this.nomJoueurTour+" "+this.nom);
      },
      (error)=>{
        console.log("Non");
      }      
    );
    
    this.http.get<any[][]>(`${apiUrl}api/GameArea/GetPersonnalBoard`, { params }).subscribe(
      (data)=>{
        this.personnalBoard=data;
        this.doSomething();
      },
      (error)=>{
        console.log("Non");
      }      
    );

    this.http.get<any[][]>(`${apiUrl}api/GameArea/GetShotBoard`, { params }).subscribe(
      (data)=>{
        this.shotBoard=data;
        this.doOther();
      },
      (error)=>{
        console.log("Non");
      }      
    );
    
  }

  doSomething(){
    const container = document.getElementById("buttonsContainer");
    if (container) {
      for (let i = 0; i < 10; i++) {
        for (let j = 0; j < 10; j++) {
          const button = document.createElement("button");
          button.classList.add("container", "water");
          const buttonId = `${i};${j}`;
          button.id = buttonId;
          if(this.personnalBoard[i][j]==0){
            button.style.backgroundColor = 'blue';
          }else if(this.personnalBoard[i][j]==1){
            button.style.backgroundColor = 'grey';
          }else if(this.personnalBoard[i][j]==2){
            button.style.backgroundColor = 'green';
          }else{
            button.style.backgroundColor = 'red';
          }
          container.appendChild(button);
        }
      }
    } else {
      console.error('Element with ID "buttonsContainer" not found.');
    }

    
  }

  doOther(){
    const containerad = document.getElementById("buttonsContainerad");
    if (containerad) {
      for (let i = 0; i < 10; i++) {
        for (let j = 0; j < 10; j++) {
          const button = document.createElement("button");
          button.classList.add("container", "water");
          const buttonId = `${i};${j}`;
          if(this.shotBoard[i][j]==0){
            button.style.backgroundColor = 'blue';
          }else if(this.shotBoard[i][j]==1){
            button.style.backgroundColor = 'grey';
          }else if(this.shotBoard[i][j]==2){
            button.style.backgroundColor = 'green';
          }else{
            button.style.backgroundColor = 'red';
          }
          button.id = buttonId;
          button.addEventListener('click', () => {
            this.tir(button.id);
          });
          containerad.appendChild(button);
        }
      }
    } else {
      console.error('Element with ID "buttonsContainer" not found.');
    }
  }


  tir(id: any) {
    this.tirer(id);
    location.reload();
    
  }

  tirer(id:any){
    if(this.nomJoueurTour!=this.nom){
      alert("Pas ton tour");
       
    }else{
      const apiUrl = 'https://localhost:7080/api/gameArea/api/players/' + this.id_player + '/shot';
      const [x, y] = id.split(';');
      const data = { 'PosX': x, 'PosY': y };
      const dataJson = JSON.stringify(data);
      const headers = new HttpHeaders({ 'Content-Type': 'application/json' });
      this.http.post(apiUrl, data,{ headers: headers }).subscribe(
        
        response => {
          this.responses.push(response);
          console.log(response);
          console.log('Response:', response);
        },
        error => {
          console.error('Error:', error);
        }
      );
    }
  }


}
