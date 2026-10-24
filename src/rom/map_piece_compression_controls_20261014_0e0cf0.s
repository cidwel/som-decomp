.setcpu "65816"
.segment "CODE"
.org $0CF0
map_control_0e0cf0:
    .byte $D6 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
