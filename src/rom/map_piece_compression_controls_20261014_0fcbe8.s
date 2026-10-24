.setcpu "65816"
.segment "CODE"
.org $CBE8
map_control_0fcbe8:
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
