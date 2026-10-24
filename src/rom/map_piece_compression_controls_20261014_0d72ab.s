.setcpu "65816"
.segment "CODE"
.org $72AB
map_control_0d72ab:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $96 ; distance low bit/count
