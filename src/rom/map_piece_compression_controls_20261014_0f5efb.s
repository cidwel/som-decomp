.setcpu "65816"
.segment "CODE"
.org $5EFB
map_control_0f5efb:
    .byte $E1 ; previous-row copy count
    .byte $D7 ; same-value copy count/distance
