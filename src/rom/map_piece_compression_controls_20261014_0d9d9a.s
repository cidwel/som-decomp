.setcpu "65816"
.segment "CODE"
.org $9D9A
map_control_0d9d9a:
    .byte $E8 ; backreference distance high bits
    .byte $33 ; distance low bit/count
