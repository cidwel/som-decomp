.setcpu "65816"
.segment "CODE"
.org $966E
map_control_0e966e:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $C3 ; same-value copy count/distance
