.setcpu "65816"
.segment "CODE"
.org $2F99
map_control_0e2f99:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
