.setcpu "65816"
.segment "CODE"
.org $B765
map_control_0fb765:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
    .byte $D7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $3D ; row-distance/count
