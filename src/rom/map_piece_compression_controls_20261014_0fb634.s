.setcpu "65816"
.segment "CODE"
.org $B634
map_control_0fb634:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
