.setcpu "65816"
.segment "CODE"
.org $27EB
map_control_0f27eb:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
