.setcpu "65816"
.segment "CODE"
.org $92F1
map_control_0f92f1:
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
