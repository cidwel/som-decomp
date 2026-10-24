.setcpu "65816"
.segment "CODE"
.org $CF63
map_control_0ecf63:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
