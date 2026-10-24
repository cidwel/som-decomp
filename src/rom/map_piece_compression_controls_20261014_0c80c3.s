.setcpu "65816"
.segment "CODE"
.org $80C3
map_control_0c80c3:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
