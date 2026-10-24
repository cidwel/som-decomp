.setcpu "65816"
.segment "CODE"
.org $6DFB
map_control_0c6dfb:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
