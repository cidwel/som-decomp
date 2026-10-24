.setcpu "65816"
.segment "CODE"
.org $50E4
map_control_0f50e4:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
