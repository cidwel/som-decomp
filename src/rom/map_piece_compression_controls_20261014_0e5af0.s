.setcpu "65816"
.segment "CODE"
.org $5AF0
map_control_0e5af0:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
