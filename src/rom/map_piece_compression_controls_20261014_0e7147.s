.setcpu "65816"
.segment "CODE"
.org $7147
map_control_0e7147:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
