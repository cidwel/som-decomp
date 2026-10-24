.setcpu "65816"
.segment "CODE"
.org $6522
map_control_0e6522:
    .byte $C3 ; same-value copy count/distance
