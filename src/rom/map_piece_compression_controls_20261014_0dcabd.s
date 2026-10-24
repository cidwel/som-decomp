.setcpu "65816"
.segment "CODE"
.org $CABD
map_control_0dcabd:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
