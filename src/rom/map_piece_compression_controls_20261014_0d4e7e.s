.setcpu "65816"
.segment "CODE"
.org $4E7E
map_control_0d4e7e:
    .byte $E4 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
