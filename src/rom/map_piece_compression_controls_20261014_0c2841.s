.setcpu "65816"
.segment "CODE"
.org $2841
map_control_0c2841:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
    .byte $C2 ; same-value copy count/distance
