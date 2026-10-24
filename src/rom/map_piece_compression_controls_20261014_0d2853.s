.setcpu "65816"
.segment "CODE"
.org $2853
map_control_0d2853:
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
