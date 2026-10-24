.setcpu "65816"
.segment "CODE"
.org $53AC
map_control_0e53ac:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
