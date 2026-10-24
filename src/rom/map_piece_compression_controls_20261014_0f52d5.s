.setcpu "65816"
.segment "CODE"
.org $52D5
map_control_0f52d5:
    .byte $D1 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
