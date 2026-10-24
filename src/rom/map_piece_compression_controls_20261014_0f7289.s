.setcpu "65816"
.segment "CODE"
.org $7289
map_control_0f7289:
    .byte $C1 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
    .byte $CA ; same-value copy count/distance
