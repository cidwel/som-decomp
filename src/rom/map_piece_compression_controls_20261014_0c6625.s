.setcpu "65816"
.segment "CODE"
.org $6625
map_control_0c6625:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
