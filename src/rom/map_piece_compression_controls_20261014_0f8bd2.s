.setcpu "65816"
.segment "CODE"
.org $8BD2
map_control_0f8bd2:
    .byte $E8 ; backreference distance high bits
    .byte $1E ; distance low bit/count
