.setcpu "65816"
.segment "CODE"
.org $CE67
map_control_0ece67:
    .byte $EF ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
