.setcpu "65816"
.segment "CODE"
.org $B300
map_control_0fb300:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
