.setcpu "65816"
.segment "CODE"
.org $58D1
map_control_0d58d1:
    .byte $E5 ; previous-row copy count
    .byte $D3 ; same-value copy count/distance
