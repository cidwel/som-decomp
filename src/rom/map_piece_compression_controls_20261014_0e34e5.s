.setcpu "65816"
.segment "CODE"
.org $34E5
map_control_0e34e5:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
