.setcpu "65816"
.segment "CODE"
.org $2200
map_control_0f2200:
    .byte $D5 ; same-value copy count/distance
