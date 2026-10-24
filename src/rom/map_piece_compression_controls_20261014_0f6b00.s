.setcpu "65816"
.segment "CODE"
.org $6B00
map_control_0f6b00:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
