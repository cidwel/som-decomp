.setcpu "65816"
.segment "CODE"
.org $9D87
map_control_0d9d87:
    .byte $EF ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
