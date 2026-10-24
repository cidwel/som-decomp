.setcpu "65816"
.segment "CODE"
.org $35D9
map_control_0d35d9:
    .byte $E1 ; previous-row copy count
    .byte $D7 ; same-value copy count/distance
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
