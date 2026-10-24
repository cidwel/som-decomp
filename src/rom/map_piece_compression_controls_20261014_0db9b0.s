.setcpu "65816"
.segment "CODE"
.org $B9B0
map_control_0db9b0:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
