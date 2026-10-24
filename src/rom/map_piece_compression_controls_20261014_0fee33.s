.setcpu "65816"
.segment "CODE"
.org $EE33
map_control_0fee33:
    .byte $EF ; backreference distance high bits
    .byte $08 ; distance low bit/count
