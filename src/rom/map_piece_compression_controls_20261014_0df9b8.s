.setcpu "65816"
.segment "CODE"
.org $F9B8
map_control_0df9b8:
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
