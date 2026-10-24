.setcpu "65816"
.segment "CODE"
.org $689F
map_control_0c689f:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
