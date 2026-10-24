.setcpu "65816"
.segment "CODE"
.org $B052
map_control_0db052:
    .byte $C1 ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
