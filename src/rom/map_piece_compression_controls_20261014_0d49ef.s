.setcpu "65816"
.segment "CODE"
.org $49EF
map_control_0d49ef:
    .byte $C6 ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
