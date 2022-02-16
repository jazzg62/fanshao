<template>
  <div id="app">
    <router-view />
  </div>
</template>

<script>
export default {
  name: "App",
  components: {},
};
</script>

<style>
#app {
}
* {
  padding: 0;
  margin: 0;
}
div {
  box-sizing: border-box;
}
input {
  box-sizing: border-box;
}
input::-webkit-outer-spin-button,
input::-webkit-inner-spin-button {
  -webkit-appearance: none;
}
input[type="number"] {
  -moz-appearance: textfield;
}
input::-webkit-input-placeholder {
  /* WebKit browsers */
  color: rgba(187, 187, 187, 1);
  font-weight: normal;
}
input:-moz-placeholder {
  /* Mozilla Firefox 4 to 18 */
  color: rgba(187, 187, 187, 1);
  font-weight: normal;
}
input::-moz-placeholder {
  /* Mozilla Firefox 19+ */
  color: rgba(187, 187, 187, 1);
  font-weight: normal;
}
input:-ms-input-placeholder {
  /* Internet Explorer 10+ */
  color: rgba(187, 187, 187, 1);
  font-weight: normal;
}

.inputLine {
  display: inline-block;
  width: 1px;
  height: 20px;
  background: #000000;
  animation-name: inputLine;
  animation-duration: 0.7s;
  animation-iteration-count: infinite;
  animation-play-state: running;
}

@keyframes inputLine {
  0% {
    opacity: 1;
  }
  50% {
    opacity: 0;
  }
  100% {
    opacity: 1;
  }
}

.el-message {
  z-index: 9999 !important;
}
</style>
