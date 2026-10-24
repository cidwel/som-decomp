.setcpu "65816"
.segment "CODE"
.org $B612
map_control_0db612:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
