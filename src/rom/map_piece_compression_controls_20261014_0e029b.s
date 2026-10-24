.setcpu "65816"
.segment "CODE"
.org $029B
map_control_0e029b:
    .byte $C7 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
