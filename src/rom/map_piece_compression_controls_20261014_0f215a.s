.setcpu "65816"
.segment "CODE"
.org $215A
map_control_0f215a:
    .byte $C2 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
