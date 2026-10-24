.setcpu "65816"
.segment "CODE"
.org $74DB
map_control_0d74db:
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
