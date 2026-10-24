.setcpu "65816"
.segment "CODE"
.org $0F7F
map_control_0d0f7f:
    .byte $E1 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
