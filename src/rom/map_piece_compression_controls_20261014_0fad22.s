.setcpu "65816"
.segment "CODE"
.org $AD22
map_control_0fad22:
    .byte $E2 ; previous-row copy count
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
