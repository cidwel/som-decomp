.setcpu "65816"
.segment "CODE"
.org $37DB
map_control_0f37db:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
