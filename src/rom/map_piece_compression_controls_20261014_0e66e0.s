.setcpu "65816"
.segment "CODE"
.org $66E0
map_control_0e66e0:
    .byte $E2 ; previous-row copy count
    .byte $C5 ; same-value copy count/distance
