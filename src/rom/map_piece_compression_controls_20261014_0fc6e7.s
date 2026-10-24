.setcpu "65816"
.segment "CODE"
.org $C6E7
map_control_0fc6e7:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
    .byte $C1 ; same-value copy count/distance
