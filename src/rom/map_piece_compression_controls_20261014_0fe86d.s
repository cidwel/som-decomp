.setcpu "65816"
.segment "CODE"
.org $E86D
map_control_0fe86d:
    .byte $EE ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
