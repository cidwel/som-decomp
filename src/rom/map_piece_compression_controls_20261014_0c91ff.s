.setcpu "65816"
.segment "CODE"
.org $91FF
map_control_0c91ff:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $8F ; distance low bit/count
