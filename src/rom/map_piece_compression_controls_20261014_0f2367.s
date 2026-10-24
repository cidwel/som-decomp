.setcpu "65816"
.segment "CODE"
.org $2367
map_control_0f2367:
    .byte $E5 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
