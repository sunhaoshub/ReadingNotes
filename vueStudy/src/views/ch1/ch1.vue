<template>
    <div id="app">
  <button @click="count++">
    Count is: {{ count }}
  </button>
</div>
</template>
<script>
import { defineComponent } from '@vue/composition-api'
import { createApp, ref } from 'vue'

createApp({
  setup() {
    return {
      count: ref(0)
    }
  }
}).mount('#app')
export default defineComponent({
    setup() {
        
    },
})
</script>
