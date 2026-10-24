.setcpu "65816"
.segment "CODE"
.org $B558
map_control_0eb558:
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
