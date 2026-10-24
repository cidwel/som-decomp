.setcpu "65816"
.segment "CODE"
.org $B971
map_control_0eb971:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
