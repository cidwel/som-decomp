.setcpu "65816"
.segment "CODE"
.org $574A
map_control_0c574a:
    .byte $EE ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
