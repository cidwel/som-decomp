.setcpu "65816"
.segment "CODE"
.org $AF94
map_control_0daf94:
    .byte $EE ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
