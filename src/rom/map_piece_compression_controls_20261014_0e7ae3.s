.setcpu "65816"
.segment "CODE"
.org $7AE3
map_control_0e7ae3:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
