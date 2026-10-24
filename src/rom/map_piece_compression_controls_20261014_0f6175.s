.setcpu "65816"
.segment "CODE"
.org $6175
map_control_0f6175:
    .byte $C1 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
