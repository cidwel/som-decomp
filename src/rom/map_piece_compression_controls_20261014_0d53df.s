.setcpu "65816"
.segment "CODE"
.org $53DF
map_control_0d53df:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
