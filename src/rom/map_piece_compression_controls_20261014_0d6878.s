.setcpu "65816"
.segment "CODE"
.org $6878
map_control_0d6878:
    .byte $C2 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $D3 ; same-value copy count/distance
