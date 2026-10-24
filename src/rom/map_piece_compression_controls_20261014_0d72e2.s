.setcpu "65816"
.segment "CODE"
.org $72E2
map_control_0d72e2:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $96 ; distance low bit/count
