.setcpu "65816"
.segment "CODE"
.org $48A6
map_control_0e48a6:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $87 ; distance low bit/count
