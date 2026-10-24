.setcpu "65816"
.segment "CODE"
.org $1FFD
map_control_0d1ffd:
    .byte $C1 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
