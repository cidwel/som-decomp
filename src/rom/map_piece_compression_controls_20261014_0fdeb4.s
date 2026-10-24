.setcpu "65816"
.segment "CODE"
.org $DEB4
map_control_0fdeb4:
    .byte $E5 ; previous-row copy count
    .byte $D7 ; same-value copy count/distance
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
