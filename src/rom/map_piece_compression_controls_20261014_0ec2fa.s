.setcpu "65816"
.segment "CODE"
.org $C2FA
map_control_0ec2fa:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
