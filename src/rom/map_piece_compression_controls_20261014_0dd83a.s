.setcpu "65816"
.segment "CODE"
.org $D83A
map_control_0dd83a:
    .byte $C5 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
