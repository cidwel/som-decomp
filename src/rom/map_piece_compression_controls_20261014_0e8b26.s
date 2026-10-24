.setcpu "65816"
.segment "CODE"
.org $8B26
map_control_0e8b26:
    .byte $C6 ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
