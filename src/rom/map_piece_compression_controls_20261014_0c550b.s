.setcpu "65816"
.segment "CODE"
.org $550B
map_control_0c550b:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
