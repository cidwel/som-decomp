.setcpu "65816"
.segment "CODE"
.org $4A1B
map_control_0d4a1b:
    .byte $C1 ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
