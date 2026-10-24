.setcpu "65816"
.segment "CODE"
.org $C98E
map_control_0fc98e:
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
