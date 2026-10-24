.setcpu "65816"
.segment "CODE"
.org $6A1E
map_control_0f6a1e:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
