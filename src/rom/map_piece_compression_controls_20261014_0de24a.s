.setcpu "65816"
.segment "CODE"
.org $E24A
map_control_0de24a:
    .byte $C4 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
