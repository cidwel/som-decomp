.setcpu "65816"
.segment "CODE"
.org $F210
map_control_0cf210:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
