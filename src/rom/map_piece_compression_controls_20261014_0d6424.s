.setcpu "65816"
.segment "CODE"
.org $6424
map_control_0d6424:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $18 ; distance low bit/count
