.setcpu "65816"
.segment "CODE"
.org $B83D
map_control_0fb83d:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
