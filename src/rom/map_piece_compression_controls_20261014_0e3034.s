.setcpu "65816"
.segment "CODE"
.org $3034
map_control_0e3034:
    .byte $CC ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
