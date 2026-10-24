.setcpu "65816"
.segment "CODE"
.org $8706
map_control_0d8706:
    .byte $CB ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
