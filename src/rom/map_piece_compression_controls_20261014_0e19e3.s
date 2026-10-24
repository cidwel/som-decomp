.setcpu "65816"
.segment "CODE"
.org $19E3
map_control_0e19e3:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
