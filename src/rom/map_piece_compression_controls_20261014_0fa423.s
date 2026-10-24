.setcpu "65816"
.segment "CODE"
.org $A423
map_control_0fa423:
    .byte $EB ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
