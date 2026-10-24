.setcpu "65816"
.segment "CODE"
.org $FA40
map_control_0ffa40:
    .byte $C2 ; same-value copy count/distance
