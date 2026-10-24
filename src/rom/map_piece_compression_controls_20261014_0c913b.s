.setcpu "65816"
.segment "CODE"
.org $913B
map_control_0c913b:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
