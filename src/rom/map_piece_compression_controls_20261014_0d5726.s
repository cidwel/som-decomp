.setcpu "65816"
.segment "CODE"
.org $5726
map_control_0d5726:
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $03 ; distance low bit/count
