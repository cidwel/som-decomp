.setcpu "65816"
.segment "CODE"
.org $81E8
map_control_0c81e8:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
