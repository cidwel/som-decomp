.setcpu "65816"
.segment "CODE"
.org $C304
map_control_0fc304:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
