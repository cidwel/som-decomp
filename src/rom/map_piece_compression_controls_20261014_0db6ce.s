.setcpu "65816"
.segment "CODE"
.org $B6CE
map_control_0db6ce:
    .byte $D9 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
