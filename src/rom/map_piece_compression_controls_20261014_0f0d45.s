.setcpu "65816"
.segment "CODE"
.org $0D45
map_control_0f0d45:
    .byte $E2 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
