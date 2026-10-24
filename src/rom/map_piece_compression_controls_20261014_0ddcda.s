.setcpu "65816"
.segment "CODE"
.org $DCDA
map_control_0ddcda:
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
