.setcpu "65816"
.segment "CODE"
.org $68B0
map_control_0c68b0:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
