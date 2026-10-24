.setcpu "65816"
.segment "CODE"
.org $2FA8
map_control_0d2fa8:
    .byte $E0 ; previous-row copy escape
    .byte $36 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $5A ; distance low bit/count
