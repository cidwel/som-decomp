.setcpu "65816"
.segment "CODE"
.org $F4FD
map_control_0ff4fd:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
