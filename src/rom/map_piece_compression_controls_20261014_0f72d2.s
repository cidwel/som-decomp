.setcpu "65816"
.segment "CODE"
.org $72D2
map_control_0f72d2:
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $2C ; distance low bit/count
