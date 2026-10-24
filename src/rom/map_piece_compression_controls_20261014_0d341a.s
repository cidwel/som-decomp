.setcpu "65816"
.segment "CODE"
.org $341A
map_control_0d341a:
    .byte $E7 ; previous-row copy count
    .byte $C4 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
