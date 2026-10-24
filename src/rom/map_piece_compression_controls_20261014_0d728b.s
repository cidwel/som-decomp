.setcpu "65816"
.segment "CODE"
.org $728B
map_control_0d728b:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
