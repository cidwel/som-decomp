.setcpu "65816"
.segment "CODE"
.org $74D6
map_control_0f74d6:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $2C ; distance low bit/count
