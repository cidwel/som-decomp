.setcpu "65816"
.segment "CODE"
.org $F2FA
map_control_0df2fa:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
