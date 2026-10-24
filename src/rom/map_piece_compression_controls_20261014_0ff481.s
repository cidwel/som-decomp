.setcpu "65816"
.segment "CODE"
.org $F481
map_control_0ff481:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
