.setcpu "65816"
.segment "CODE"
.org $0B6F
map_control_0f0b6f:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
