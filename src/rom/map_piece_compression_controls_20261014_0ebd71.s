.setcpu "65816"
.segment "CODE"
.org $BD71
map_control_0ebd71:
    .byte $C6 ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
