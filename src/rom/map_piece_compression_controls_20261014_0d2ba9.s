.setcpu "65816"
.segment "CODE"
.org $2BA9
map_control_0d2ba9:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
    .byte $C5 ; same-value copy count/distance
