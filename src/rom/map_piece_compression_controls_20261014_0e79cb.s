.setcpu "65816"
.segment "CODE"
.org $79CB
map_control_0e79cb:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
