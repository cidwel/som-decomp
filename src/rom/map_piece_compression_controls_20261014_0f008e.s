.setcpu "65816"
.segment "CODE"
.org $008E
map_control_0f008e:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
