.setcpu "65816"
.segment "CODE"
.org $F340
map_control_0df340:
    .byte $D1 ; same-value copy count/distance
