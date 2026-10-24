.setcpu "65816"
.segment "CODE"
.org $5159
map_control_0d5159:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
