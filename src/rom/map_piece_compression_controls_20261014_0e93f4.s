.setcpu "65816"
.segment "CODE"
.org $93F4
map_control_0e93f4:
    .byte $D4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
    .byte $C6 ; same-value copy count/distance
