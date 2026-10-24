.setcpu "65816"
.segment "CODE"
.org $82E9
map_control_0c82e9:
    .byte $E8 ; backreference distance high bits
    .byte $32 ; distance low bit/count
