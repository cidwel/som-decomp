.setcpu "65816"
.segment "CODE"
.org $DF40
map_control_0fdf40:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
    .byte $C5 ; same-value copy count/distance
