.setcpu "65816"
.segment "CODE"
.org $0C6D
map_control_0c0c6d:
    .byte $E1 ; previous-row copy count
    .byte $D9 ; same-value copy count/distance
