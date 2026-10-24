.setcpu "65816"
.segment "CODE"
.org $C445
map_control_0fc445:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $C1 ; same-value copy count/distance
