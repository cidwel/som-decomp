.setcpu "65816"
.segment "CODE"
.org $326C
map_control_0d326c:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
