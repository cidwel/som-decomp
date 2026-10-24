.setcpu "65816"
.segment "CODE"
.org $E01E
map_control_0de01e:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
