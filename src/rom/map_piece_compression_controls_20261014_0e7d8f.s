.setcpu "65816"
.segment "CODE"
.org $7D8F
map_control_0e7d8f:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
