.setcpu "65816"
.segment "CODE"
.org $60CF
map_control_0d60cf:
    .byte $C1 ; same-value copy count/distance
