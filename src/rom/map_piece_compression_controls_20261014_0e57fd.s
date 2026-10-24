.setcpu "65816"
.segment "CODE"
.org $57FD
map_control_0e57fd:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
