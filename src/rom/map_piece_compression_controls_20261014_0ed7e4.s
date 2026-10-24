.setcpu "65816"
.segment "CODE"
.org $D7E4
map_control_0ed7e4:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
