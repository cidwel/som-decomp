.setcpu "65816"
.segment "CODE"
.org $8B02
map_control_0d8b02:
    .byte $E2 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
