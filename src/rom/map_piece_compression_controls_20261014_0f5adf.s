.setcpu "65816"
.segment "CODE"
.org $5ADF
map_control_0f5adf:
    .byte $C2 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
