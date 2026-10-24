.setcpu "65816"
.segment "CODE"
.org $A2FA
map_control_0da2fa:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
