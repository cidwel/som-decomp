.setcpu "65816"
.segment "CODE"
.org $B066
map_control_0eb066:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
