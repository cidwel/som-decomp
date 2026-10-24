.setcpu "65816"
.segment "CODE"
.org $0F04
map_control_0f0f04:
    .byte $CC ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
