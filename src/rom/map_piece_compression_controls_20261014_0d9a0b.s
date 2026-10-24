.setcpu "65816"
.segment "CODE"
.org $9A0B
map_control_0d9a0b:
    .byte $E4 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
