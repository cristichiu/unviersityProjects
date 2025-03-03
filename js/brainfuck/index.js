class Compiler {
    constructor() {
        this.constructor = new Map()
        this.deCodedConstructor = new Map()
        this.model = new Map()
        this.deCodedModel = new Map()
        this.init()
    }
    init() {
        this.addConstructor()
        this.enCodeNumber()
        this.addDeCodedConstructor()
        this.addDeCodedModel()
    }
    addConstructor() {
        // baisic
        this.constructor.set('false', '![]')
        this.constructor.set('true', '!![]')
        this.constructor.set('undefined', '[][[]]')
        this.constructor.set('NaN', '+[![]]')
        this.constructor.set('11e100', '+!+[]+[+!+[]]+(!+[]+[])[!+[]+!+[]+!+[]]+[+!+[]]+[+[]]+[+[]]')
        this.constructor.set('1e1000', '+!+[]+(!+[]+[])[!+[]+!+[]+!+[]]+[+!+[]]+[+[]]+[+[]]+[+[]]')
        this.constructor.set('flat', '(![]+[])[+[]]+(![]+[])[+!+[]+!+[]]+(![]+[])[+!+[]]+(!![]+[])[+[]]')
    }
    addDeCodedConstructor() {
        // avansat
        this.deCodedConstructor.set('entries', `(true+[])[3]+(undefined+[])[1]+(true+[])[0]+(true+[])[1]+([false]+undefined)[1+[0]]+(true+[])[3]+(false+[])[3]`)
        this.deCodedConstructor.set('1.1e+101', '+(11e100)')
        this.deCodedConstructor.set('Infinity', '+(1e1000)')
        this.deCodedConstructor.set('ArrayIterator', '[][entries]()')
        this.deCodedConstructor.set('ArrayPrototypeFlat', '[][flat]')
        this.deCodedConstructor.set('subZero', '(+(11e100)+[])[1]+[0]+[0]+[0]+[0]+[0]+[0]+[1]') // .0000001
        this.deCodedConstructor.set('constructor', '(ArrayPrototypeFlat+[])[3]+([true]+ArrayPrototypeFlat)[1+[0]]+(undefined+[])[1]+(false+[])[3]+(true+[])[0]+(true+[])[1]+(undefined+[])[0]+(ArrayPrototypeFlat+[])[3]+(true+[])[0]+(ArrayIterator+[])[1]+(true+[])[1]')
        this.deCodedConstructor.set('1e-7', '+(subZero+[])')
        this.deCodedConstructor.set('Boolean', '(![])[constructor+[]]')
        this.deCodedConstructor.set('Number', '(+[])[constructor+[]]')
        this.deCodedConstructor.set('return', '(true+[])[1]+(true+[])[3]+(true+[])[0]+(true+[])[2]+(true+[])[1]+(undefined+[])[1]')
        this.deCodedConstructor.set('italics', '(undefined+[])[5]+(true+[])[0]+(false+[])[1]+(false+[])[2]+(undefined+[])[5]+(constructor+[])[0]+(false+[])[3]')
        this.deCodedConstructor.set('String', '([]+[])[constructor+[]]')
        this.deCodedConstructor.set('Function', '[][flat+[]][constructor+[]]')
        this.deCodedConstructor.set('name', '(undefined+[])[1]+(false+[])[1]+([]+(+[])[constructor+[]])[1+[1]]+(true+[])[3]')
        this.deCodedConstructor.set('toSitring', '(true+[])[0]+([true]+[][flat+[]])[1+[0]]+([]+[])[constructor+[]][name+[]]')
        this.deCodedConstructor.set('slice', '(false+[])[3]+(false+[])[2]+([false]+undefined)[1+[0]]+([][flat+[]]+[])[3]+(true+[])[3]')
        this.deCodedConstructor.set('minusOne', '(+(subZero)+[])[2]+[+!+[]]')
        this.deCodedConstructor.set('trysetring', '(true+[])[0]+(true+[])[1]+(true+[Infinity])[1+[1]]+([true]+[][flat+[]])[2+[0]]+([]+[])[constructor+[]][name+[]]+([]+[][flat+[]])[1+[3]]+([]+[][flat+[]])[1+[4]]+(+(11e100+[])+[])[1]+(undefined+[])[1]+([true]+[][flat+[]])[1+[0]]+(true+[])[1]+([]+(+[])[constructor+[]])[1+[1]]+(false+[])[1]+(false+[])[2]+([false]+undefined)[1+[0]]+(+(3+[5]))[toSitring+[]](3+[6])+(true+[])[3]+([]+[][flat+[]])[1+[3]]+![]+([]+[][flat+[]])[1+[4]]+([true]+[][flat+[]])[slice+[]](minusOne+[])+([][flat+[]]+[])[3]+(false+[])[1]+(true+[])[0]+([][flat+[]]+[])[3]+(+(1+[0]+[1]))[toSitring+[]](2+[1])[1]+([]+[][flat+[]])[1+[3]]+(false+[])[0]+([]+[][flat+[]])[1+[4]]+([true]+[][flat+[]])[2+[0]]+(true+[])[1]+(true+[])[3]+(true+[])[0]+(undefined+[])[0]+(true+[])[1]+(undefined+[])[1]+([false]+[][flat+[]])[2+[0]]+(false+[])[0]+([true]+[][flat+[]])[slice+[]](minusOne+[])')
        this.deCodedConstructor.set('RangeError', '[][flat+[]][constructor+[]](trysetring+[])()')
        // this.deCodedConstructor.set('returnRegExp', '')
        this.deCodedConstructor.set('RegExp', 'Function((return)+[]+((false+[0])["italics"]()[[1]+[0]])+[]+false+((false+[0])["italics"]()[[1]+[0]])+[])()')
        this.enCodeConstructor()
    }
    enCodeNumber() {
        // adaug cifrele codate
        for(let i=0; i<10; i++) {
            let t = ''; for(let j=0; j<i; j++) { t += '+!+[]' }
            this.constructor.set(i+[], `+[]${t}`)
        }
    }
    enCodeConstructor() {
        // compilez chestiile avansate si le transfer in baisic doar ca sunt inca avansate
        this.deCodedConstructor.forEach((value, key) => {
            this.deCodedConstructor.forEach((value1, key1) => {
                value = value.replaceAll(key1, value1)
            })
            this.deCodedConstructor.set(key, value)
        })
        this.deCodedConstructor.forEach((value, key) => {
            this.constructor.forEach((value1, key1) => {
                value = value.replaceAll(key1, value1)
            })
            this.constructor.set(key, value)
            this.deCodedConstructor.delete(key)
        })
    }
    addDeCodedModel() {
        // model aproape decodat..
        this.deCodedModel.set('0', '0+[]')
        this.deCodedModel.set('1', '1+[]')
        this.deCodedModel.set('2', '2+[]')
        this.deCodedModel.set('3', '3+[]')
        this.deCodedModel.set('4', '4+[]')
        this.deCodedModel.set('5', '5+[]')
        this.deCodedModel.set('6', '6+[]')
        this.deCodedModel.set('7', '7+[]')
        this.deCodedModel.set('8', '8+[]')
        this.deCodedModel.set('9', '9+[]')
        this.deCodedModel.set('a', '(false+[])[1]')
        this.deCodedModel.set('b', '([]+(+[])[constructor+[]])[1+[2]]')
        this.deCodedModel.set('c', '([][flat+[]]+[])[3]')
        this.deCodedModel.set('d', '(undefined+[])[2]')
        this.deCodedModel.set('e', '(true+[])[3]')
        this.deCodedModel.set('f', '(false+[])[0]')
        this.deCodedModel.set('g', '(false+[0]+([]+[])[constructor+[]])[2+[0]]')
        this.deCodedModel.set('h', '(+([1]+[0]+[1]))[((true)+[])[0]+((Boolean)+[])[[1]+[1]]+String[(name)+[]]]([2]+[1])[1]')
        this.deCodedModel.set('i', '([false]+undefined)[1+[0]]')
        this.deCodedModel.set('j', '([]+[][entries+[]]())[3]')
        this.deCodedModel.set('k', '(+([2]+[0]))[((true)+[])[0]+((Boolean)+[])[[1]+[1]]+String[(name)+[]]]([2]+[1])')
        this.deCodedModel.set('l', '(false+[])[2]')
        this.deCodedModel.set('m', '([]+(+[])[constructor+[]])[1+[1]]')
        this.deCodedModel.set('n', '(undefined+[])[1]')
        this.deCodedModel.set('o', '([true]+[][flat+[]])[1+[0]]')
        //p
        //q
        this.deCodedModel.set('r', '(true+[])[1]')
        this.deCodedModel.set('s', '(false+[])[3]')
        this.deCodedModel.set('t', '(true+[])[0]')
        this.deCodedModel.set('u', '(undefined+[])[0]')
        //v
        //w
        //x
        this.deCodedModel.set('y', '(true+[Infinity])[1+[1]]')
        //z
        this.deCodedModel.set('A', '([NaN]+([]+[][entries+[]]()))[1+[1]]')
        this.deCodedModel.set('B', '([NaN]+(![])[constructor+[]])[1+[2]]')
        //C
        //D
        this.deCodedModel.set('E', '(RangeError+[])[5]')
        this.deCodedModel.set('F', '([NaN]+[][flat+[]][constructor+[]])[1+[2]]')
        //G
        //H
        this.deCodedModel.set('I', '(Infinity+[])[0]')
        //J
        //K
        //L
        //M
        this.deCodedModel.set('N', '(NaN+[])[0]')
        //O
        //P
        //Q
        this.deCodedModel.set('R', '(RangeError+[])[0]')
        this.deCodedModel.set('S', '([NaN]+([]+[])[constructor+[]])[1+[2]]')
        //T
        //U
        //V
        //W
        //X
        //Y
        //W
        this.deCodedModel.set(' ', '([false]+[][flat+[]])[2+[0]]')
        this.deCodedModel.set('(', '([]+[][flat+[]])[1+[3]]')
        this.deCodedModel.set(')', '([]+[][flat+[]])[1+[4]]')
        this.deCodedModel.set('[', '([]+[][entries+[]]())[0]')
        this.deCodedModel.set(']', '([]+[][entries+[]]())[2+[2]]')
        this.deCodedModel.set('{', '([true]+[][flat+[]])[2+[0]]')
        this.deCodedModel.set('}', '([][flat+[]]+[]+[])[slice+[]](minusOne+[])') //3
        this.deCodedModel.set('+', '(+(11e100+[])+[])[4]')
        this.deCodedModel.set('.', '(+(11e100+[])+[])[1]')
        this.deCodedModel.set('-', '(+(subZero+[])+[])[2]')
        this.deCodedModel.set('/', '([]+[][flat+[]][constructor+[]](returnRegExp+[])()())[0]') //3
        this.deCodedModel.set(':', '([]+[][flat+[]][constructor+[]](returnRegExp+[])()())[3]') //3 
        this.deCodedModel.set('?', '([]+[][flat+[]][constructor+[]](returnRegExp+[])()())[2]') //3
        this.deCodedModel.set('\\', '([]+RegExp((([]+[][flat+[]][constructor+[]](returnRegExp+[])()())[0])+[]))[1]') //3
        this.enCodeModel()
    }
    enCodeModel() {
        // codez modelu
        this.deCodedModel.forEach((value, key) => {
            this.constructor.forEach((value1, key1) => {
                value = value.replaceAll(key1, value1)
            })
            this.model.set(key, value)
            this.deCodedModel.delete(key)
        })
    }
    compile(text) {
        //finalu
        let result = []
        text = text.split('')
        text.forEach(txt => {
            try{
                const findModel = this.model.get(txt)
                if(findModel) {
                    result.push(this.model.get(txt))
                } else {
                    result.push(txt)
                }
            }catch{console.log('SomeError')}
        })
        return result.join("+")
    }
}

const compiler = new Compiler()

function testCompiler() {
    compiler.model.forEach(value => {
        try{
            console.log((value))
        }catch{ console.log("error") }
    })
}
testCompiler()

const y = process.openStdin()
y.addListener("data", res => {
    let x = res.toString().trim()
    console.log(compiler.compile(x))
})
