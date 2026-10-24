.setcpu "65816"
.segment "CODE"
.org $61CD
map_control_0f61cd:
    .byte $CA ; same-value copy count/distance
