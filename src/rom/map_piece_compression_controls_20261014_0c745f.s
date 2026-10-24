.setcpu "65816"
.segment "CODE"
.org $745F
map_control_0c745f:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
