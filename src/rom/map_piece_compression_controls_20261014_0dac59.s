.setcpu "65816"
.segment "CODE"
.org $AC59
map_control_0dac59:
    .byte $EF ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $95 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $23 ; distance low bit/count
