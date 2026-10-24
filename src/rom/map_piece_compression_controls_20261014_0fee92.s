.setcpu "65816"
.segment "CODE"
.org $EE92
map_control_0fee92:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
