import  Particle    from './Particle';

class   ParticlePool{
    private firstAvailable_:any;
    static  POOL_SIZE:number=100;
    private particles_:Particle[]=[];

    constructor(){
        for(let i=0;i<ParticlePool.POOL_SIZE;i++){
            this.particles_[i]=new Particle;
        }

        this.firstAvailable_=this.particles_[0];
        for(let i=0;i<ParticlePool.POOL_SIZE-1;i++){
            this.particles_[i].setNext(this.particles_[i+1]);
        }
        this.particles_[ParticlePool.POOL_SIZE-1].setNext(null);
    }

    create(x:number,y:number,xVel:number,yVel:number,lifetime:number){
        if(this.firstAvailable_==null){
            console.error(`this.firstAvalable==null`);
            return;
        }

        let newParticle:Particle=this.firstAvailable_ as Particle;
        this.firstAvailable_=newParticle.getNext();

        newParticle.init(x,y,xVel,yVel,lifetime);
    }

    animate():void{
        for(let i=0;i<ParticlePool.POOL_SIZE;i++){
            if(this.particles_[i].animate()){
                this.particles_[i].setNext(this.firstAvailable_);
                this.firstAvailable_=this.particles_[i];
            }
        }
    }
}
