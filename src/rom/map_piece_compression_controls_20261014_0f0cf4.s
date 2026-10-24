.setcpu "65816"
.segment "CODE"
.org $0CF4
map_control_0f0cf4:
    .byte $C5 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
    .byte $D9 ; same-value copy count/distance
