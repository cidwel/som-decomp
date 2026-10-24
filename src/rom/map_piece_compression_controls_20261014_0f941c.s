.setcpu "65816"
.segment "CODE"
.org $941C
map_control_0f941c:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
