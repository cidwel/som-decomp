.setcpu "65816"
.segment "CODE"
.org $F6AF
map_control_0cf6af:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
