.setcpu "65816"
.segment "CODE"
.org $139F
map_control_0e139f:
    .byte $E9 ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
