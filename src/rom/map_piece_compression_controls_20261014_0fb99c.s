.setcpu "65816"
.segment "CODE"
.org $B99C
map_control_0fb99c:
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
