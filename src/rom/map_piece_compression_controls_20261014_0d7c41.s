.setcpu "65816"
.segment "CODE"
.org $7C41
map_control_0d7c41:
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
