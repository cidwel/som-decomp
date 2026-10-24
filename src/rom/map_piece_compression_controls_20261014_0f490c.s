.setcpu "65816"
.segment "CODE"
.org $490C
map_control_0f490c:
    .byte $C3 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
