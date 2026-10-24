.setcpu "65816"
.segment "CODE"
.org $D2BD
map_control_0ed2bd:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
