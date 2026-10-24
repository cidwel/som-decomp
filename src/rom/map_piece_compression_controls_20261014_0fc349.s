.setcpu "65816"
.segment "CODE"
.org $C349
map_control_0fc349:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $48 ; row-distance/count
