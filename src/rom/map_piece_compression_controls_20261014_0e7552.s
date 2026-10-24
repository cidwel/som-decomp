.setcpu "65816"
.segment "CODE"
.org $7552
map_control_0e7552:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
