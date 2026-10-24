.setcpu "65816"
.segment "CODE"
.org $E8A6
map_control_0fe8a6:
    .byte $EE ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
