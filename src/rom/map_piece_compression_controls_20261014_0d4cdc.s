.setcpu "65816"
.segment "CODE"
.org $4CDC
map_control_0d4cdc:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
