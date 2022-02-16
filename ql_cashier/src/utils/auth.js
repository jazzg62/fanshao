const TokenKey = 'token'

export function getToken() {
    return localStorage.getItem(TokenKey)
}

export function setToken(token) {
    // console.log(token)
    return localStorage.setItem(TokenKey, token)
}

export function removeToken() {
    return localStorage.removeItem(TokenKey)
}

export function setSessionStorage(key,data) {
     return sessionStorage.setItem(key,data)
}

export function getSessionStorage(key) {
    return sessionStorage.getItem(key)
}

export function removeSessionStorage(key) {
    return sessionStorage.removeItem(key)
}