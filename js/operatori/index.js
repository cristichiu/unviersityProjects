let str = "A and B and C and D and E and F and G and H and I and J and K and L and M"
let operatori = [ "or", "and", "not", ")", "(" ]
let vars = []
let values = []
let res = []
let strForm = str.split(" ")

for(let i=0; i<strForm.length; i++) {
    if(!operatori.includes(strForm[i])) {
        if(!vars.includes(strForm[i])) vars.push(strForm[i])
    }
}

let leg = Math.pow(2, vars.length) / 2
let start = false

for(let i=0; i<vars.length; i++) {
    let temp = leg
    values.push([])
    for(let j=0; j<Math.pow(2, vars.length); j++) {
        if(!temp) { temp = leg; start = !start }
        values[i].push(start)
        temp-- 
    }
    leg /= 2
    start = false
}

let org = str

str = str.replaceAll("or", "||")
str = str.replaceAll("and", "&&")
str = str.replaceAll("not ", "!")

for(let i=0; i<values[0].length; i++) {
    let newStr = str
    for(let j=0; j<vars.length; j++) {
        newStr = newStr.replaceAll(vars[j], values[j][i])
    }
    res.push( eval(newStr) )
}

let resStr = ""

for(let i=0; i<vars.length; i++) {
    resStr += vars[i] + " | "
}
resStr += org + "\n" 

for(let i=0; i<res.length; i++) {
    for(let j=0; j<vars.length; j++) resStr += (values[j][i] ? 1 : 0) + " | "
    resStr += (res[i] ? 1 : 0) + "\n"
}

console.log(resStr)
