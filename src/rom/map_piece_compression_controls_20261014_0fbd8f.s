.setcpu "65816"
.segment "CODE"
.org $BD8F
map_control_0fbd8f:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $C2 ; same-value copy count/distance
