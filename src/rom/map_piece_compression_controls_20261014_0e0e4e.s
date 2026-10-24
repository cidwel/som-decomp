.setcpu "65816"
.segment "CODE"
.org $0E4E
map_control_0e0e4e:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $C1 ; same-value copy count/distance
