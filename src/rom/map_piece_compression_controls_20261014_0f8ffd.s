.setcpu "65816"
.segment "CODE"
.org $8FFD
map_control_0f8ffd:
    .byte $C2 ; same-value copy count/distance
