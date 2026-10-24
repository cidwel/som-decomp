.setcpu "65816"
.segment "CODE"
.org $53BE
map_control_0e53be:
    .byte $D7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
