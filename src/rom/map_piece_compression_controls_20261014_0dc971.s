.setcpu "65816"
.segment "CODE"
.org $C971
map_control_0dc971:
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
