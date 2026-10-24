.setcpu "65816"
.segment "CODE"
.org $F8FA
map_control_0ff8fa:
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
