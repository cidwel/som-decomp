.setcpu "65816"
.segment "CODE"
.org $6A6C
map_control_0d6a6c:
    .byte $C2 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $D5 ; same-value copy count/distance
