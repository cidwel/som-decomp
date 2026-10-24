.setcpu "65816"
.segment "CODE"
.org $420A
map_control_0f420a:
    .byte $F1 ; progressive-copy count
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
