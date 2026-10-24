.setcpu "65816"
.segment "CODE"
.org $E100
map_control_0de100:
    .byte $C4 ; same-value copy count/distance
