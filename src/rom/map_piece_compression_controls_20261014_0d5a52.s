.setcpu "65816"
.segment "CODE"
.org $5A52
map_control_0d5a52:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
