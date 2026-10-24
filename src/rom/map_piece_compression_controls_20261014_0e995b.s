.setcpu "65816"
.segment "CODE"
.org $995B
map_control_0e995b:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
