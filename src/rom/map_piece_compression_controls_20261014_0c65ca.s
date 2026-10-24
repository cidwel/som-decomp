.setcpu "65816"
.segment "CODE"
.org $65CA
map_control_0c65ca:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count
