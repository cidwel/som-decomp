.setcpu "65816"
.segment "CODE"
.org $8F30
map_control_0e8f30:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
