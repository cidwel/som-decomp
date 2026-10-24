.setcpu "65816"
.segment "CODE"
.org $C16B
map_control_0ec16b:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
