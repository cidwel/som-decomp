.setcpu "65816"
.segment "CODE"
.org $C2F3
map_control_0fc2f3:
    .byte $E0 ; previous-row copy escape
    .byte $48 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $9D ; row-distance/count
