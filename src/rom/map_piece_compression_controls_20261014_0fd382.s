.setcpu "65816"
.segment "CODE"
.org $D382
map_control_0fd382:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
