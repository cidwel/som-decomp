.setcpu "65816"
.segment "CODE"
.org $180B
map_control_0f180b:
    .byte $EF ; backreference distance high bits
    .byte $09 ; distance low bit/count
