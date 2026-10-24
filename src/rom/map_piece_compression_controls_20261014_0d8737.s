.setcpu "65816"
.segment "CODE"
.org $8737
map_control_0d8737:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
