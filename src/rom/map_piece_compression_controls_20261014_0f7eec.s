.setcpu "65816"
.segment "CODE"
.org $7EEC
map_control_0f7eec:
    .byte $E8 ; backreference distance high bits
    .byte $8E ; distance low bit/count
