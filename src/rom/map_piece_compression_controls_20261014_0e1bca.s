.setcpu "65816"
.segment "CODE"
.org $1BCA
map_control_0e1bca:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $C4 ; same-value copy count/distance
