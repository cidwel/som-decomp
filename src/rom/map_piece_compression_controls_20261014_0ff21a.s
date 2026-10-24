.setcpu "65816"
.segment "CODE"
.org $F21A
map_control_0ff21a:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
