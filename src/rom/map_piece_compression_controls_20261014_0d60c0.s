.setcpu "65816"
.segment "CODE"
.org $60C0
map_control_0d60c0:
    .byte $C2 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
