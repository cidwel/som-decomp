.setcpu "65816"
.segment "CODE"
.org $F107
map_control_0ff107:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
