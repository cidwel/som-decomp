.setcpu "65816"
.segment "CODE"
.org $AAB8
map_control_0faab8:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
