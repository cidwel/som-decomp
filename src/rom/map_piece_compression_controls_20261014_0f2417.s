.setcpu "65816"
.segment "CODE"
.org $2417
map_control_0f2417:
    .byte $C5 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
