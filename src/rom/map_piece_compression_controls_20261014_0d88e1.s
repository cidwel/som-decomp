.setcpu "65816"
.segment "CODE"
.org $88E1
map_control_0d88e1:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
