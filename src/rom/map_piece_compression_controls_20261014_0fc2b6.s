.setcpu "65816"
.segment "CODE"
.org $C2B6
map_control_0fc2b6:
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
