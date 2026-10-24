.setcpu "65816"
.segment "CODE"
.org $ADEA
map_control_0eadea:
    .byte $C5 ; same-value copy count/distance
