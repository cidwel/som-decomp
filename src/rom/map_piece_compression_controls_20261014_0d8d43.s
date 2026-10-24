.setcpu "65816"
.segment "CODE"
.org $8D43
map_control_0d8d43:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
