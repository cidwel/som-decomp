.setcpu "65816"
.segment "CODE"
.org $E020
map_control_0ee020:
    .byte $C1 ; same-value copy count/distance
