.setcpu "65816"
.segment "CODE"
.org $17A5
map_control_0d17a5:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
