.setcpu "65816"
.segment "CODE"
.org $CECD
map_control_0dcecd:
    .byte $C1 ; same-value copy count/distance
