.setcpu "65816"
.segment "CODE"
.org $5FAB
map_control_0d5fab:
    .byte $E2 ; previous-row copy count
    .byte $CD ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
