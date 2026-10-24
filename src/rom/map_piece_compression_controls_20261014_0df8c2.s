.setcpu "65816"
.segment "CODE"
.org $F8C2
map_control_0df8c2:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
