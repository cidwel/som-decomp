.setcpu "65816"
.segment "CODE"
.org $C801
map_control_0ec801:
    .byte $C1 ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
