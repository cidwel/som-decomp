.setcpu "65816"
.segment "CODE"
.org $391B
map_control_0c391b:
    .byte $ED ; backreference distance high bits
    .byte $07 ; distance low bit/count
