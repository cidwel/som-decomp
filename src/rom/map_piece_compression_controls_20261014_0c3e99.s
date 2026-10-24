.setcpu "65816"
.segment "CODE"
.org $3E99
map_control_0c3e99:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
