.setcpu "65816"
.segment "CODE"
.org $876F
map_control_0e876f:
    .byte $C2 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
    .byte $D9 ; same-value copy count/distance
