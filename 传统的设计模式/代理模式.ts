export interface   Subject{
    sailBook():void;
}

class   RealSubjectBook implements  Subject{
    sailBook():void{
        console.log("sail book");
    }
}

export  class   dangdangProxy   implements  Subject{
    sailBook():void{
        let subject:Subject=new RealSubjectBook();
        this.disconnect();
        subject.sailBook();
        this.disconnect();
    }

    disconnect():void{
        console.log('disconnect');
    }
}