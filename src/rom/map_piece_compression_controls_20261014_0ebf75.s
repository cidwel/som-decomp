.setcpu "65816"
.segment "CODE"
.org $BF75
map_control_0ebf75:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
