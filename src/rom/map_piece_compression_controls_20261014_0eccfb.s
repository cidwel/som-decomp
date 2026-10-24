.setcpu "65816"
.segment "CODE"
.org $CCFB
map_control_0eccfb:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
