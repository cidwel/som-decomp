.setcpu "65816"
.segment "CODE"
.org $274C
map_control_0d274c:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
