.setcpu "65816"
.segment "CODE"
.org $9DC9
map_control_0f9dc9:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $89 ; distance low bit/count
