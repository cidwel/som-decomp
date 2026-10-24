.setcpu "65816"
.segment "CODE"
.org $F371
map_control_0df371:
    .byte $C1 ; same-value copy count/distance
    .byte $DA ; same-value copy count/distance
