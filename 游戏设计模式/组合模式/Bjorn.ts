
class   Volume{}
class   Sprite{}
class   World{
    resolveCollision(volume:Volume,x:number,y:number,velocity:number):void{}
}
class   Graphics{
    draw(sprite:Sprite,x:number,y:number):void{}
}
class   Controller{
    static getJoystickDirection():number
    {
        return 0;
    }
}
const   DIR_LEFT:number=0;
const   DIR_RIGHT:number=1;

class   Bjorn{
    static  WALK_ACCELERATION:number=1;
    velocity_:number;
    x_:number;
    y_:number;
    volume_:Volume=new Volume();
    spriteStand_:Sprite=new Sprite();
    spriteWalkLeft_:Sprite=new Sprite();
    spriteWalkRight_:Sprite=new Sprite();

    constructor(velocity:number=0,x_:number=0,y_:number=0){
        this.velocity_=velocity;
        this.x_=x_;
        this.y_=y_;
    }

    update(world:World,graphics:Graphics):void{
        switch(Controller.getJoystickDirection()){
            case   DIR_LEFT:
                this.velocity_-=Bjorn.WALK_ACCELERATION;
                break;
            case    DIR_RIGHT:
                this.velocity_+=Bjorn.WALK_ACCELERATION;
                break; 
        }

        this.x_+=this.velocity_;
        world.resolveCollision(this.volume_,this.x_,this.y_,this.velocity_);

        let sprite:Sprite=this.spriteStand_;
        if(this.velocity_<0)sprite=this.spriteWalkLeft_;
        else if(this.velocity_>0)sprite=this.spriteWalkRight_;

        graphics.draw(sprite,this.x_,this.y_);
    }
}