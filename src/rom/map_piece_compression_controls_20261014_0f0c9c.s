.setcpu "65816"
.segment "CODE"
.org $0C9C
map_control_0f0c9c:
    .byte $E4 ; previous-row copy count
    .byte $D2 ; same-value copy count/distance
