.setcpu "65816"
.segment "CODE"
.org $6A3F
map_control_0f6a3f:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
