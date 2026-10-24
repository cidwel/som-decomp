.setcpu "65816"
.segment "CODE"
.org $D662
map_control_0dd662:
    .byte $E3 ; previous-row copy count
    .byte $CB ; same-value copy count/distance
