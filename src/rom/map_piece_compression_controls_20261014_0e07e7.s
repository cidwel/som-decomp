.setcpu "65816"
.segment "CODE"
.org $07E7
map_control_0e07e7:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
