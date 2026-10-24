.setcpu "65816"
.segment "CODE"
.org $E7BC
map_control_0fe7bc:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
