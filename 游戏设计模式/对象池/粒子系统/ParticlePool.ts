import  Particle   from './Particle';

class   ParticlePool{
    static  POOL_SIZE:number=100;
    private particles_:Particle[]=[];
    constructor(){
        for(let i=0;i<ParticlePool.POOL_SIZE;i++){
            this.particles_[i]=new Particle;
        }
    }

    animate():void{
        for(let i=0;i<ParticlePool.POOL_SIZE;i++){
            this.particles_[i].animate();
        }
    }

    create(x:number,y:number,xVel:number,yVel:number,lifetime:number):void{
        for(let i=0;i<ParticlePool.POOL_SIZE;i++){
            if(!this.particles_[i].inUse()){
                this.particles_[i].init(x,y,xVel,yVel,lifetime);
                return;
            }
        }
    }
}