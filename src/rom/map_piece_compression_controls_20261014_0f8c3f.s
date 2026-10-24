.setcpu "65816"
.segment "CODE"
.org $8C3F
map_control_0f8c3f:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
