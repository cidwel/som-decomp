.setcpu "65816"
.segment "CODE"
.org $4F3E
map_control_0f4f3e:
    .byte $C1 ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
