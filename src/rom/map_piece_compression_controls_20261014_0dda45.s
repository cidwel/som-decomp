.setcpu "65816"
.segment "CODE"
.org $DA45
map_control_0dda45:
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
