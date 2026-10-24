.setcpu "65816"
.segment "CODE"
.org $EC91
map_control_0fec91:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
