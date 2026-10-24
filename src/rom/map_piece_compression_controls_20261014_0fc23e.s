.setcpu "65816"
.segment "CODE"
.org $C23E
map_control_0fc23e:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
