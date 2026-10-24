.setcpu "65816"
.segment "CODE"
.org $78FC
map_control_0e78fc:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $04 ; distance low bit/count
