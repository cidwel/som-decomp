.setcpu "65816"
.segment "CODE"
.org $1DFF
map_control_0f1dff:
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $1B ; distance low bit/count
