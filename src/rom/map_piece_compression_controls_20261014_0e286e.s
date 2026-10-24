.setcpu "65816"
.segment "CODE"
.org $286E
map_control_0e286e:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $D1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
