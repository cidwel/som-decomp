.setcpu "65816"
.segment "CODE"
.org $FC47
map_control_0efc47:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
