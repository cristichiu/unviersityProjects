const matDeAdiacenta1 = [
    [0,1,0,0,0],
    [1,0,1,1,1],
    [0,1,0,1,1],
    [0,1,1,0,0],
    [0,1,1,0,0]
]

const matDeAdiacenta2 = [
    [0,1,0,0,0],
    [1,0,1,0,1],
    [0,1,0,1,0],
    [0,0,1,0,0],
    [0,1,0,0,0]
]

const matDeAdiacenta3 = [
    [0,0,0,0,0],
    [0,0,0,0,0],
    [0,0,0,0,0],
    [0,0,0,0,0],
    [0,0,0,0,0]
]

class SetStabilInterior {
    constructor(matriceDeAdiacenta) {
        this.matriceDeAdiacenta = matriceDeAdiacenta
        this.inversaMatriceDeAdiacenta = []
        this.f = []
        this.nextF = [...this.f]
        this.iteratii = 0
        this.result = []
    }
    pasu1() {
        this.inversaMatriceDeAdiacenta = this.matriceDeAdiacenta.map(l => { return l.map(s => s?0:1) })
        this.pasu2()
    }
    pasu2() {
        this.inversaMatriceDeAdiacenta.forEach((r, i) => {
            let a = []
            r.forEach((u, j) => { if (u) a.push(j + 1) })
            this.f.push({ l: new Set([i + 1]), c: new Set(a) })
        })
        this.pasu3()
    }
    pasu3() {
        this.iteratii++
        this.nextF = [...this.f]
        for (let i = 0; i < this.f.length; i++) {
            for (let j = i + 1; j < this.f.length; j++) {
                let reuniune = { l: this.f[i].l.union(this.f[j].l), c: this.f[i].c.intersection(this.f[j].c) }
                let intersectie = { l: this.f[i].l.intersection(this.f[j].l), c: this.f[i].c.union(this.f[j].c) }
                if (reuniune.l.size && reuniune.c.size) this.nextF.push(reuniune)
                if (intersectie.l.size && intersectie.c.size) this.nextF.push(intersectie)
            }
        }
        this.pasu4()
    }
    pasu4() {
        for (let i = 0; i < this.nextF.length; i++) {
            let found = false
            for (let j = 0; j < this.nextF.length; j++) {
                if (i != j) {
                    if (this.nextF[i].l.isSubsetOf(this.nextF[j].l) && this.nextF[i].c.isSubsetOf(this.nextF[j].c)) {
                        found = true
                        break;
                    }
                }
            }
            if (found) {
                this.nextF.splice(i, 1)
                i--
            }
        }
        this.pasu5()
    }
    pasu5() {
        let stop = true
        if (this.f.length == this.nextF.length) {
            for (let i = 0; i < this.f.length; i++) {
                let found = false
                for (let j = 0; j < this.nextF.length; j++) {
                    if (this.f[i].l.size == this.nextF[j].l.size && this.f[i].c.size == this.nextF[j].c.size) {
                        if (this.f[i].l.isSubsetOf(this.nextF[j].l) && this.f[i].c.isSubsetOf(this.nextF[j].c)) {
                            found = true
                            break
                        }
                    }
                }
                if (!found) {
                    stop = false
                    break
                }
            }
        } else stop = false
        if (stop) {
            this.nextF.forEach(t => {
                if (t.l.size == t.c.size && t.l.isSubsetOf(t.c)) this.result.push([...t.l].sort())
            })
            return
        }
        this.f = [...this.nextF]
        this.pasu3()
    }
    calculate = this.pasu1
    showResult() {
        this.result.forEach(r => {
            console.log(r.join(", "))
        })
        console.log("Rezultat optinut din:", this.iteratii)
    }
}

let mat1 = new SetStabilInterior(matDeAdiacenta1)
let mat2 = new SetStabilInterior(matDeAdiacenta2)
let mat3 = new SetStabilInterior(matDeAdiacenta3)

mat1.calculate()
mat2.calculate()
mat3.calculate()

mat1.showResult()
mat2.showResult()
mat3.showResult()