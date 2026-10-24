.setcpu "65816"
.segment "CODE"
.org $1064
map_control_0f1064:
    .byte $EE ; backreference distance high bits
    .byte $99 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $73 ; distance low bit/count
