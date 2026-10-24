.setcpu "65816"
.segment "CODE"
.org $2FA7
map_control_0f2fa7:
    .byte $E2 ; previous-row copy count
    .byte $C5 ; same-value copy count/distance
