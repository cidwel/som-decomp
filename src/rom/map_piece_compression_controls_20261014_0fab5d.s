.setcpu "65816"
.segment "CODE"
.org $AB5D
map_control_0fab5d:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
