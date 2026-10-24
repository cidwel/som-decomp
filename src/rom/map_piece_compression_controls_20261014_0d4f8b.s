.setcpu "65816"
.segment "CODE"
.org $4F8B
map_control_0d4f8b:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
