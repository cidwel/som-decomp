.setcpu "65816"
.segment "CODE"
.org $3E96
map_control_0c3e96:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
