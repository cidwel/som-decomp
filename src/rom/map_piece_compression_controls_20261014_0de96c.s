.setcpu "65816"
.segment "CODE"
.org $E96C
map_control_0de96c:
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $C5 ; same-value copy count/distance
