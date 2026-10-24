.setcpu "65816"
.segment "CODE"
.org $D26D
map_control_0ed26d:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
