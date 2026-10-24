.setcpu "65816"
.segment "CODE"
.org $11B6
map_control_0d11b6:
    .byte $E8 ; backreference distance high bits
    .byte $99 ; distance low bit/count
