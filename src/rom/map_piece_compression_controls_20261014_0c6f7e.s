.setcpu "65816"
.segment "CODE"
.org $6F7E
map_control_0c6f7e:
    .byte $C2 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
