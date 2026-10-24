.setcpu "65816"
.segment "CODE"
.org $DA10
map_control_0dda10:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
    .byte $C4 ; same-value copy count/distance
