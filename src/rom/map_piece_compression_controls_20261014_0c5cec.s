.setcpu "65816"
.segment "CODE"
.org $5CEC
map_control_0c5cec:
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
