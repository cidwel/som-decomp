.setcpu "65816"
.segment "CODE"
.org $D1FE
map_control_0fd1fe:
    .byte $E2 ; previous-row copy count
    .byte $C5 ; same-value copy count/distance
