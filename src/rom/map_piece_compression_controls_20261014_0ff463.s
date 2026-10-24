.setcpu "65816"
.segment "CODE"
.org $F463
map_control_0ff463:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
