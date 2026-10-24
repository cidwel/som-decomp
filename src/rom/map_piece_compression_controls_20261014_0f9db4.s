.setcpu "65816"
.segment "CODE"
.org $9DB4
map_control_0f9db4:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
