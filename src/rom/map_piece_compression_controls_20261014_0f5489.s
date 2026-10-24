.setcpu "65816"
.segment "CODE"
.org $5489
map_control_0f5489:
    .byte $E8 ; backreference distance high bits
    .byte $1E ; distance low bit/count
