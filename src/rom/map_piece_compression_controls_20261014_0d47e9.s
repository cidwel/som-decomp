.setcpu "65816"
.segment "CODE"
.org $47E9
map_control_0d47e9:
    .byte $C3 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
