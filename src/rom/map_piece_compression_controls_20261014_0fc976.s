.setcpu "65816"
.segment "CODE"
.org $C976
map_control_0fc976:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
