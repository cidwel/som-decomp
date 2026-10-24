.setcpu "65816"
.segment "CODE"
.org $57EA
map_control_0f57ea:
    .byte $C9 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
