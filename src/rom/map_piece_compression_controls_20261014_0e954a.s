.setcpu "65816"
.segment "CODE"
.org $954A
map_control_0e954a:
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
