.setcpu "65816"
.segment "CODE"
.org $599B
map_control_0e599b:
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
