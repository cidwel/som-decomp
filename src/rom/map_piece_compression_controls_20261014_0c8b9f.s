.setcpu "65816"
.segment "CODE"
.org $8B9F
map_control_0c8b9f:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
