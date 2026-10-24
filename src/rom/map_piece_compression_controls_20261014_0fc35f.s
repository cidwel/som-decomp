.setcpu "65816"
.segment "CODE"
.org $C35F
map_control_0fc35f:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $74 ; row-distance/count
