.setcpu "65816"
.segment "CODE"
.org $08DB
map_control_0f08db:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
