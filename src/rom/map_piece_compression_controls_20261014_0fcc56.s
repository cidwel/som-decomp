.setcpu "65816"
.segment "CODE"
.org $CC56
map_control_0fcc56:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
