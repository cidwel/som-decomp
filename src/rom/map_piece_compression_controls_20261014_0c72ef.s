.setcpu "65816"
.segment "CODE"
.org $72EF
map_control_0c72ef:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $D2 ; same-value copy count/distance
