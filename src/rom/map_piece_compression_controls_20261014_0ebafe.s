.setcpu "65816"
.segment "CODE"
.org $BAFE
map_control_0ebafe:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
