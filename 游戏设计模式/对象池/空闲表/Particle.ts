import  State from './State';

export  default class   Particle{
    state_:State=new State;
    private framesLeft_:number=0;

    getNext():Particle{
        let next=this.state_.next as Particle;
        return  next;
    }

    setNext(next:any):void{
        this.state_.next=next;
    }

    inUse():boolean{return this.framesLeft_>0;}

    init(x:number,y:number,xVel:number,yVel:number,lifetime:number):void{
        this.state_.x=x;
        this.state_.y=y;
        this.state_.xVel=xVel;
        this.state_.yVel=yVel;
        this.framesLeft_=lifetime;
    }

    animate():boolean{
        if(!this.inUse()) return false;

        this.framesLeft_--;
        this.state_.x+=this.state_.xVel;
        this.state_.y+=this.state_.yVel;

        return this.framesLeft_==0;
    }
}