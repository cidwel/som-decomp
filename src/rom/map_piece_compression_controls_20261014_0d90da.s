.setcpu "65816"
.segment "CODE"
.org $90DA
map_control_0d90da:
    .byte $DF ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
