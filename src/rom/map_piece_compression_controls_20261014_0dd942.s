.setcpu "65816"
.segment "CODE"
.org $D942
map_control_0dd942:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
