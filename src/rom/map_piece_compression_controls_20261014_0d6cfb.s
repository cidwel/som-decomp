.setcpu "65816"
.segment "CODE"
.org $6CFB
map_control_0d6cfb:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
