.setcpu "65816"
.segment "CODE"
.org $6FD9
map_control_0d6fd9:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
