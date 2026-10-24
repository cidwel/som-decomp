.setcpu "65816"
.segment "CODE"
.org $6375
map_control_0e6375:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
