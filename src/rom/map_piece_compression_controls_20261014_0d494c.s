.setcpu "65816"
.segment "CODE"
.org $494C
map_control_0d494c:
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
