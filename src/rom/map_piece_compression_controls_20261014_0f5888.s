.setcpu "65816"
.segment "CODE"
.org $5888
map_control_0f5888:
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
