.setcpu "65816"
.segment "CODE"
.org $7BAD
map_control_0f7bad:
    .byte $C1 ; same-value copy count/distance
