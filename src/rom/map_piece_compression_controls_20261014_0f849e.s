.setcpu "65816"
.segment "CODE"
.org $849E
map_control_0f849e:
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
