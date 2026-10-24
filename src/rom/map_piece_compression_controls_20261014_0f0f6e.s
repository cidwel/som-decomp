.setcpu "65816"
.segment "CODE"
.org $0F6E
map_control_0f0f6e:
    .byte $C1 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
