.setcpu "65816"
.segment "CODE"
.org $9C87
map_control_0d9c87:
    .byte $EF ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $1B ; distance low bit/count
