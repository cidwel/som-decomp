.setcpu "65816"
.segment "CODE"
.org $0D0E
map_control_0c0d0e:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $C1 ; same-value copy count/distance
