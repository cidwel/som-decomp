.setcpu "65816"
.segment "CODE"
.org $EA67
map_control_0fea67:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
