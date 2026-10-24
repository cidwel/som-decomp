.setcpu "65816"
.segment "CODE"
.org $8B02
map_control_0e8b02:
    .byte $C6 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
