.setcpu "65816"
.segment "CODE"
.org $31C0
map_control_0f31c0:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
    .byte $C4 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
    .byte $C9 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
