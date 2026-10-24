.setcpu "65816"
.segment "CODE"
.org $56BB
map_control_0f56bb:
    .byte $C1 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
