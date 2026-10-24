.setcpu "65816"
.segment "CODE"
.org $72FF
map_control_0e72ff:
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
