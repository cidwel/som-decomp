.setcpu "65816"
.segment "CODE"
.org $3570
map_control_0f3570:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
