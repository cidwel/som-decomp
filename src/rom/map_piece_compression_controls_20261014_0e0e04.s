.setcpu "65816"
.segment "CODE"
.org $0E04
map_control_0e0e04:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
