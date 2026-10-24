.setcpu "65816"
.segment "CODE"
.org $06EA
map_control_0e06ea:
    .byte $E2 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
