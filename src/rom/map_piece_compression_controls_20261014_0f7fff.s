.setcpu "65816"
.segment "CODE"
.org $7FFF
map_control_0f7fff:
    .byte $C1 ; same-value copy count/distance
