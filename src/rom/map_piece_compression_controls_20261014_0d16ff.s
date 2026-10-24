.setcpu "65816"
.segment "CODE"
.org $16FF
map_control_0d16ff:
    .byte $D1 ; same-value copy count/distance
