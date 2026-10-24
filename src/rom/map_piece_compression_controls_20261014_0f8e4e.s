.setcpu "65816"
.segment "CODE"
.org $8E4E
map_control_0f8e4e:
    .byte $D4 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
