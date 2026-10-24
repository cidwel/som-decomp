.setcpu "65816"
.segment "CODE"
.org $0FCD
map_control_0d0fcd:
    .byte $D1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
