.setcpu "65816"
.segment "CODE"
.org $1A4B
map_control_0d1a4b:
    .byte $C6 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
