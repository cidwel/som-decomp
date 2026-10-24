.setcpu "65816"
.segment "CODE"
.org $6C6D
map_control_0c6c6d:
    .byte $E1 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
