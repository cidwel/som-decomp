.setcpu "65816"
.segment "CODE"
.org $F7C5
map_control_0cf7c5:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
