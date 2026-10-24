.setcpu "65816"
.segment "CODE"
.org $9CAF
map_control_0d9caf:
    .byte $E2 ; previous-row copy count
    .byte $C4 ; same-value copy count/distance
