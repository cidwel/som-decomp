.setcpu "65816"
.segment "CODE"
.org $47A4
map_control_0d47a4:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
