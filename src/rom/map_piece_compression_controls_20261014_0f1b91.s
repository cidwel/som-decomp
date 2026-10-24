.setcpu "65816"
.segment "CODE"
.org $1B91
map_control_0f1b91:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
