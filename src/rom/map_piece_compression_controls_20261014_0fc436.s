.setcpu "65816"
.segment "CODE"
.org $C436
map_control_0fc436:
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count
    .byte $D4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
