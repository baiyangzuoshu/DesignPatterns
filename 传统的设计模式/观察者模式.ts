export  class   PlayserObserver{
    update(action:string):void{
        console.log(`action:${action}`);
    }
}

export  class   Secretary{
    private list:PlayserObserver[]=[];
    constructor(){
        this.list=[];
    }

    addPlayerObserver(player:PlayserObserver){
        this.list.push(player);
    }

    Notify(action:string):void{
        for(let i=0;i<this.list.length;i++){
            this.list[i].update(action);
        }
    }
}