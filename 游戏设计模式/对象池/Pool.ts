export  class   Pool{
    constructor(){}

    static _poolDic:any={}
    static POOLSIGN:string = "__InPool";

    static getPoolBySign(sign:string) {
        return Pool._poolDic[sign] || (Pool._poolDic[sign] = []);
    }

    static recover(sign:string, item:any) {
        if (item[Pool.POOLSIGN])
            return;
        item[Pool.POOLSIGN] = true;
        Pool.getPoolBySign(sign).push(item);
    }

    static getItemByClass(sign:string, cls:any) {
        if (!Pool._poolDic[sign])
            return new cls();
        var pool = Pool.getPoolBySign(sign);
        if (pool.length) {
            var rst = pool.pop();
            rst[Pool.POOLSIGN] = false;
        }
        else {
            rst = new cls();
        }
        return rst;
    }
};
