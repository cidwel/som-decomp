.setcpu "65816"
.segment "CODE"
.org $F5A0
map_control_0ff5a0:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
