.setcpu "65816"
.segment "CODE"
.org $A037
map_control_0ea037:
    .byte $D1 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
