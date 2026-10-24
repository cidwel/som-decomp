.setcpu "65816"
.segment "CODE"
.org $2FA0
map_control_0d2fa0:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
