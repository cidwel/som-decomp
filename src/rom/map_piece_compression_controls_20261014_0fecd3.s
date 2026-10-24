.setcpu "65816"
.segment "CODE"
.org $ECD3
map_control_0fecd3:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
