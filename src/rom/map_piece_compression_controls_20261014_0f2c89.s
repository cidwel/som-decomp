.setcpu "65816"
.segment "CODE"
.org $2C89
map_control_0f2c89:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $C3 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
