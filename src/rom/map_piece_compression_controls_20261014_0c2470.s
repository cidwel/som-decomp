.setcpu "65816"
.segment "CODE"
.org $2470
map_control_0c2470:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
    .byte $C2 ; same-value copy count/distance
