.setcpu "65816"
.segment "CODE"
.org $422E
map_control_0f422e:
    .byte $C1 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
