.setcpu "65816"
.segment "CODE"
.org $156C
map_control_0c156c:
    .byte $C4 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $D1 ; same-value copy count/distance
