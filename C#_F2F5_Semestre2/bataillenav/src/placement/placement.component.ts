import { Component } from '@angular/core';
import { AfterViewInit } from '@angular/core';
import { HttpClient, HttpParams, HttpHeaders } from '@angular/common/http';
import { ActivatedRoute, Router } from '@angular/router';
@Component({
  selector: 'app-tableau-boutons',
  templateUrl: './placement.component.html',
  styleUrls: ['./placement.component.css']
})

export class PlacementComponent implements AfterViewInit {

  constructor(private http: HttpClient,private route: ActivatedRoute,private router: Router) {
    this.id_player=this.route.snapshot.queryParams['id_player'];
    this.id_session=this.route.snapshot.queryParams['id_session'];
    this.nom=this.route.snapshot.queryParams['nom'];
   }

  tailles: number[] = [5,4,3,3,2];
  taille:number=0;
  id_player:number;
  id_session:number;
  nom:string;
  selectedChoice: string="Horizontal";
  
  personnalBoard: any[][] = [];

  onRadioChange(event:any) {
    this.selectedChoice = event.target.value;
    console.log(this.selectedChoice);
  }

  ngAfterViewInit() {
    if(localStorage.getItem('taillesSav')!=null){
      let temp=localStorage.getItem('taillesSav');
      if(temp!=null){
        this.tailles=JSON.parse(temp);
      }
    }
    console.log(this.tailles.length);
    let apiUrl = 'https://localhost:7080/';
    let params = new HttpParams().set('id', this.id_player);
    this.http.get<any[][]>(`${apiUrl}api/GameArea/GetPersonnalBoard`, { params }).subscribe(
      (data)=>{
        this.personnalBoard=data;
        this.doSomething();
      },
      (error)=>{
        console.log("Non");
      }      
    );
    
  }

    doSomething(){

      
      let maDiv = document.querySelector('#buttonsContainer');
      if(maDiv!=null){
        maDiv.innerHTML="";
      }
      const container = document.getElementById("buttonsContainer");
      this.taille=this.tailles[0];
      if(this.tailles.length==0){
        this.router.navigate(['game'],{ queryParams: { id_player: this.id_player,id_session:this.id_session,nom:this.nom } });
      }
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
            button.addEventListener('click', () => {
              this.tir(button.id);
            });
            container.appendChild(button);
          }
        }
      } else {
        console.error('Element with ID "buttonsContainer" not found.');
      }
    }

  tir(id:string){
    let choix;
    if(this.selectedChoice=="Horizontal"){
      choix=1;
    }else{
      choix=0;
    }
    let apiUrl = 'https://localhost:7080/api/gameArea/api/sessions/players/' + this.id_player + '/placeship';
    const [x, y] = id.split(';');
    const data = { 'taille':this.tailles.shift(),'h':choix, 'PosX': x, 'PosY': y };
    console.log(data);
    const headers = new HttpHeaders({ 'Content-Type': 'application/json' });
    this.http.post<any>(apiUrl, data,{ headers: headers }).subscribe(
      response => {
        console.log('Response:', response);
      },
      error => {
        console.error('Error:', error);
      }
    );
    apiUrl = 'https://localhost:7080/';
    let params = new HttpParams().set('id', this.id_player);
    this.http.get<any[][]>(`${apiUrl}api/GameArea/GetPersonnalBoard`, { params }).subscribe(
      (data)=>{
        this.personnalBoard=data;
        this.doSomething();
      },
      (error)=>{
        console.log("Non");
      }      
    );
    localStorage.setItem('taillesSav', JSON.stringify(this.tailles));
    location.reload();
  }

  public onButtonClick(buttonId: string): void {
    const button = document.getElementById(buttonId);
    console.log(button);
    if (button) {
      button.style.backgroundColor = 'red';
    }
  }
  
}