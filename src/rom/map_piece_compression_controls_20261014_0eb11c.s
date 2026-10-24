.setcpu "65816"
.segment "CODE"
.org $B11C
map_control_0eb11c:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
