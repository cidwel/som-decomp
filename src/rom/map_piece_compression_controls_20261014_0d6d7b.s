.setcpu "65816"
.segment "CODE"
.org $6D7B
map_control_0d6d7b:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
