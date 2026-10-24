.setcpu "65816"
.segment "CODE"
.org $2DF5
map_control_0f2df5:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
