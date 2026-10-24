.setcpu "65816"
.segment "CODE"
.org $E632
map_control_0de632:
    .byte $C6 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
