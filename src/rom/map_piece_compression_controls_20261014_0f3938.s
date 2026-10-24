.setcpu "65816"
.segment "CODE"
.org $3938
map_control_0f3938:
    .byte $C2 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
