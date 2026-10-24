.setcpu "65816"
.segment "CODE"
.org $FEEC
map_control_0dfeec:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
