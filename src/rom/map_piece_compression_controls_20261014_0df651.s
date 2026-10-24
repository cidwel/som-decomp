.setcpu "65816"
.segment "CODE"
.org $F651
map_control_0df651:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
