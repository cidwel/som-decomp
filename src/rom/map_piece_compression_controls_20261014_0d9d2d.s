.setcpu "65816"
.segment "CODE"
.org $9D2D
map_control_0d9d2d:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $AA ; row-distance/count
    .byte $C6 ; same-value copy count/distance
