.setcpu "65816"
.segment "CODE"
.org $15B1
map_control_0d15b1:
    .byte $E0 ; previous-row copy escape
    .byte $2C ; row-distance/count
    .byte $C6 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
