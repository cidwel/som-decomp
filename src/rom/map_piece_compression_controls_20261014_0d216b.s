.setcpu "65816"
.segment "CODE"
.org $216B
map_control_0d216b:
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
