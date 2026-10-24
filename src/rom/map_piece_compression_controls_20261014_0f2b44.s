.setcpu "65816"
.segment "CODE"
.org $2B44
map_control_0f2b44:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
