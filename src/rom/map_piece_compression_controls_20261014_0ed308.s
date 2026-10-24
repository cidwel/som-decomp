.setcpu "65816"
.segment "CODE"
.org $D308
map_control_0ed308:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
