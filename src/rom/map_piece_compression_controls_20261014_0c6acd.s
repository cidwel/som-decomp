.setcpu "65816"
.segment "CODE"
.org $6ACD
map_control_0c6acd:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
