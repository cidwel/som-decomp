.setcpu "65816"
.segment "CODE"
.org $C992
map_control_0fc992:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $94 ; row-distance/count
