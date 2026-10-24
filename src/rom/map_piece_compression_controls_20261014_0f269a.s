.setcpu "65816"
.segment "CODE"
.org $269A
map_control_0f269a:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $73 ; distance low bit/count
