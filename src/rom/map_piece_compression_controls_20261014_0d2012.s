.setcpu "65816"
.segment "CODE"
.org $2012
map_control_0d2012:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
