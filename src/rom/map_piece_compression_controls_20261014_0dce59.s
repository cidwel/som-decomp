.setcpu "65816"
.segment "CODE"
.org $CE59
map_control_0dce59:
    .byte $E2 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
