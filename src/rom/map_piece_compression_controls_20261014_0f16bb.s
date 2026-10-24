.setcpu "65816"
.segment "CODE"
.org $16BB
map_control_0f16bb:
    .byte $C1 ; same-value copy count/distance
