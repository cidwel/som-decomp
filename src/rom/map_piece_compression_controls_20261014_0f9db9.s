.setcpu "65816"
.segment "CODE"
.org $9DB9
map_control_0f9db9:
    .byte $D7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
