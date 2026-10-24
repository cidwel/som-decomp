.setcpu "65816"
.segment "CODE"
.org $7840
map_control_0f7840:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
