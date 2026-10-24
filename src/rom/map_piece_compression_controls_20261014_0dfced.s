.setcpu "65816"
.segment "CODE"
.org $FCED
map_control_0dfced:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
