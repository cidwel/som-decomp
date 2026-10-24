.setcpu "65816"
.segment "CODE"
.org $AB65
map_control_0fab65:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
