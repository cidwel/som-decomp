.setcpu "65816"
.segment "CODE"
.org $6308
map_control_0f6308:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
