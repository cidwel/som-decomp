.setcpu "65816"
.segment "CODE"
.org $EF38
map_control_0fef38:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
