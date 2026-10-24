.setcpu "65816"
.segment "CODE"
.org $45A4
map_control_0f45a4:
    .byte $E0 ; previous-row copy escape
    .byte $34 ; row-distance/count
    .byte $C4 ; same-value copy count/distance
