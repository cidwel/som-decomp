.setcpu "65816"
.segment "CODE"
.org $4E64
map_control_0f4e64:
    .byte $CD ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
