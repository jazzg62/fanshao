<template>
    <span>{{ now }}</span>
</template>

<script>
import {formatDate } from '../common.js';
export default {
    name: "Timer",
    data: () => {
        return {
            now: formatDate(new Date(), 'yyyy/MM/dd一hh:mm:ss'),
        };
    },
    beforeMount: function () {
        setInterval(
            () => {
                this.now = formatDate(new Date(), 'yyyy/MM/dd一hh:mm:ss');
            },
            1000
        );
    },
};
</script>