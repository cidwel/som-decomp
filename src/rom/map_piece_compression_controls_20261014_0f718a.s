.setcpu "65816"
.segment "CODE"
.org $718A
map_control_0f718a:
    .byte $D1 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
