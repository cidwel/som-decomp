.setcpu "65816"
.segment "CODE"
.org $AFD0
map_control_0eafd0:
    .byte $CC ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
