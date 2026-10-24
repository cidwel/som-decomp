.setcpu "65816"
.segment "CODE"
.org $F43E
map_control_0ff43e:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
