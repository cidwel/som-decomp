.setcpu "65816"
.segment "CODE"
.org $EEF8
map_control_0eeef8:
    .byte $E6 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
