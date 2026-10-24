.setcpu "65816"
.segment "CODE"
.org $A566
map_control_0fa566:
    .byte $EC ; backreference distance high bits
    .byte $8F ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $0D ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $04 ; distance low bit/count
