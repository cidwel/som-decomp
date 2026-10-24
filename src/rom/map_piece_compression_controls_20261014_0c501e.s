.setcpu "65816"
.segment "CODE"
.org $501E
map_control_0c501e:
    .byte $EE ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
