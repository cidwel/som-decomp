.setcpu "65816"
.segment "CODE"
.org $DFBD
map_control_0ddfbd:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
