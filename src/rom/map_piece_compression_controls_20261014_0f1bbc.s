.setcpu "65816"
.segment "CODE"
.org $1BBC
map_control_0f1bbc:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
