.setcpu "65816"
.segment "CODE"
.org $6A1A
map_control_0d6a1a:
    .byte $C1 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
