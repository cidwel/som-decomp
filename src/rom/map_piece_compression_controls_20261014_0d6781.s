.setcpu "65816"
.segment "CODE"
.org $6781
map_control_0d6781:
    .byte $E1 ; previous-row copy count
    .byte $D5 ; same-value copy count/distance
