.setcpu "65816"
.segment "CODE"
.org $BA56
map_control_0fba56:
    .byte $EB ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $05 ; distance low bit/count
