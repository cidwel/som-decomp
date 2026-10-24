.setcpu "65816"
.segment "CODE"
.org $2DF1
map_control_0f2df1:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
