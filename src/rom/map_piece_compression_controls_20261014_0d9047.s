.setcpu "65816"
.segment "CODE"
.org $9047
map_control_0d9047:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
