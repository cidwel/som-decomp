.setcpu "65816"
.segment "CODE"
.org $BB5A
map_control_0ebb5a:
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
