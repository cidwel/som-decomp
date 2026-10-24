.setcpu "65816"
.segment "CODE"
.org $BE68
map_control_0ebe68:
    .byte $E0 ; previous-row copy escape
    .byte $3A ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7E ; row-distance/count
    .byte $D9 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $3A ; row-distance/count
