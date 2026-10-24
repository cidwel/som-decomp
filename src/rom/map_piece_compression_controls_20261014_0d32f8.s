.setcpu "65816"
.segment "CODE"
.org $32F8
map_control_0d32f8:
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
