.setcpu "65816"
.segment "CODE"
.org $C3C8
map_control_0fc3c8:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
    .byte $D1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $43 ; row-distance/count
