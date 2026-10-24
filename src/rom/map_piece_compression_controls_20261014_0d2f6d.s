.setcpu "65816"
.segment "CODE"
.org $2F6D
map_control_0d2f6d:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
