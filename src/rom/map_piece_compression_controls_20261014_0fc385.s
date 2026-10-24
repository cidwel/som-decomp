.setcpu "65816"
.segment "CODE"
.org $C385
map_control_0fc385:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $31 ; row-distance/count
