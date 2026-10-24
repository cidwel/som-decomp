.setcpu "65816"
.segment "CODE"
.org $7C10
map_control_0f7c10:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
