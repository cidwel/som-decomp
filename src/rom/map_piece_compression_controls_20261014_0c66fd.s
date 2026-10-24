.setcpu "65816"
.segment "CODE"
.org $66FD
map_control_0c66fd:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
