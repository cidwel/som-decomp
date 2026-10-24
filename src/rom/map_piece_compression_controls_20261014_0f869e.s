.setcpu "65816"
.segment "CODE"
.org $869E
map_control_0f869e:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $7C ; distance low bit/count
