.setcpu "65816"
.segment "CODE"
.org $BE12
map_control_0dbe12:
    .byte $E1 ; previous-row copy count
    .byte $D1 ; same-value copy count/distance
