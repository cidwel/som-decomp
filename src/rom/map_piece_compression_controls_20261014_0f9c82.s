.setcpu "65816"
.segment "CODE"
.org $9C82
map_control_0f9c82:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
