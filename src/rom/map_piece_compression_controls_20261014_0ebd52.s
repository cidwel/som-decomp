.setcpu "65816"
.segment "CODE"
.org $BD52
map_control_0ebd52:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
