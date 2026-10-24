.setcpu "65816"
.segment "CODE"
.org $2F6C
map_control_0f2f6c:
    .byte $E8 ; backreference distance high bits
    .byte $8F ; distance low bit/count
