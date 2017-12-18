/**************************************

Rot 13 is reversible
Use: "Hello World".rot13()
=> "Uryyb Jbeyq"

**************************************/
String.prototype.rot13 = function() {
    return this.replace(/([a-m])|([n-z])/ig, function(a,b,c) {
        return String.fromCharCode(b ? b.charCodeAt(0) + 13 : c ? c.charCodeAt(0) - 13 : 0) || a;
    });
}
