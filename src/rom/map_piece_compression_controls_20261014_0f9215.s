.setcpu "65816"
.segment "CODE"
.org $9215
map_control_0f9215:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
