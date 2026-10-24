.setcpu "65816"
.segment "CODE"
.org $86DB
map_control_0d86db:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $1B ; distance low bit/count
