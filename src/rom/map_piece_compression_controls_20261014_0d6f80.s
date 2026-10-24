.setcpu "65816"
.segment "CODE"
.org $6F80
map_control_0d6f80:
    .byte $C6 ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
