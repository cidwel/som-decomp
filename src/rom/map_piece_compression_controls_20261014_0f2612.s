.setcpu "65816"
.segment "CODE"
.org $2612
map_control_0f2612:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
