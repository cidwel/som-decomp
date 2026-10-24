.setcpu "65816"
.segment "CODE"
.org $BD76
map_control_0ebd76:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $C1 ; same-value copy count/distance
