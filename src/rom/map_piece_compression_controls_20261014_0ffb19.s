.setcpu "65816"
.segment "CODE"
.org $FB19
map_control_0ffb19:
    .byte $D1 ; same-value copy count/distance
