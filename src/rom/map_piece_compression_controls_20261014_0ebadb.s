.setcpu "65816"
.segment "CODE"
.org $BADB
map_control_0ebadb:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
