.setcpu "65816"
.segment "CODE"
.org $CC26
map_control_0dcc26:
    .byte $E1 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
