.setcpu "65816"
.segment "CODE"
.org $1C5E
map_control_0f1c5e:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
