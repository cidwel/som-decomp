.setcpu "65816"
.segment "CODE"
.org $9AEC
map_control_0f9aec:
    .byte $C1 ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
