.setcpu "65816"
.segment "CODE"
.org $3FDC
map_control_0e3fdc:
    .byte $F1 ; progressive-copy count
    .byte $C2 ; same-value copy count/distance
