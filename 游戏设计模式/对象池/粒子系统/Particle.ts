export  default class   Particle{
    private framesLeft_:number;
    private x_:number=0;
    private y_:number=0;
    private xVel_:number=0;
    private yVel_:number=0;
    constructor(framesLeft_=0){
        this.framesLeft_=framesLeft_;
    }

    animate():void{
        if(!this.inUse())return;

        this.framesLeft_--;
        this.x_+=this.xVel_;
        this.y_+=this.yVel_;
    }

    init(x:number,y:number,xVel:number,yVel:number,lifetime:number):void{
        this.x_=x;
        this.y_=y;
        this.xVel_=xVel;
        this.yVel_=yVel;
        this.framesLeft_=lifetime;
    }

    inUse():boolean{return this.framesLeft_>0;}
}