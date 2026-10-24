.setcpu "65816"
.segment "CODE"
.org $70DD
map_control_0f70dd:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
