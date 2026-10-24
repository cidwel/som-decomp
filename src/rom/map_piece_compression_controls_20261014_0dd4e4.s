.setcpu "65816"
.segment "CODE"
.org $D4E4
map_control_0dd4e4:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
    .byte $C4 ; same-value copy count/distance
