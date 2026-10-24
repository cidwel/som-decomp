.setcpu "65816"
.segment "CODE"
.org $434A
map_control_0f434a:
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
