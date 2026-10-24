.setcpu "65816"
.segment "CODE"
.org $CAF6
map_control_0ecaf6:
    .byte $E8 ; backreference distance high bits
    .byte $32 ; distance low bit/count
