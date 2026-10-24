.setcpu "65816"
.segment "CODE"
.org $395A
map_control_0d395a:
    .byte $F1 ; progressive-copy count
    .byte $E1 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
