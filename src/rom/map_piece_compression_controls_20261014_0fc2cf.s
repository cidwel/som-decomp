.setcpu "65816"
.segment "CODE"
.org $C2CF
map_control_0fc2cf:
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $52 ; row-distance/count
