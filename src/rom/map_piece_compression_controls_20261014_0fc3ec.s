.setcpu "65816"
.segment "CODE"
.org $C3EC
map_control_0fc3ec:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $4E ; row-distance/count
