.setcpu "65816"
.segment "CODE"
.org $B000
map_control_0eb000:
    .byte $ED ; backreference distance high bits
    .byte $04 ; distance low bit/count
