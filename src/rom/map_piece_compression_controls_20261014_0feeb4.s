.setcpu "65816"
.segment "CODE"
.org $EEB4
map_control_0feeb4:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
