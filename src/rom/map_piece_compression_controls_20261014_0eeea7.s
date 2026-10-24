.setcpu "65816"
.segment "CODE"
.org $EEA7
map_control_0eeea7:
    .byte $E1 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
