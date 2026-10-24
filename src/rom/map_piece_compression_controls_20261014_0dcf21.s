.setcpu "65816"
.segment "CODE"
.org $CF21
map_control_0dcf21:
    .byte $C5 ; same-value copy count/distance
