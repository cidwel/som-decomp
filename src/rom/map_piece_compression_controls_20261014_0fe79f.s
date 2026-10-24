.setcpu "65816"
.segment "CODE"
.org $E79F
map_control_0fe79f:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
