.setcpu "65816"
.segment "CODE"
.org $F019
map_control_0ff019:
    .byte $DD ; same-value copy count/distance
