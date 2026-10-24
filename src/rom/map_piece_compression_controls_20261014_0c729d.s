.setcpu "65816"
.segment "CODE"
.org $729D
map_control_0c729d:
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
