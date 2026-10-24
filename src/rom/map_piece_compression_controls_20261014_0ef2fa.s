.setcpu "65816"
.segment "CODE"
.org $F2FA
map_control_0ef2fa:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
