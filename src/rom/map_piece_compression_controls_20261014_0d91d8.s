.setcpu "65816"
.segment "CODE"
.org $91D8
map_control_0d91d8:
    .byte $E1 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
