.setcpu "65816"
.segment "CODE"
.org $9DA7
map_control_0d9da7:
    .byte $E8 ; backreference distance high bits
    .byte $33 ; distance low bit/count
