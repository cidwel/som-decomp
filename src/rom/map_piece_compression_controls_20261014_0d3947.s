.setcpu "65816"
.segment "CODE"
.org $3947
map_control_0d3947:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
    .byte $DD ; same-value copy count/distance
