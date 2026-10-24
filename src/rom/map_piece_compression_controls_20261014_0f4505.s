.setcpu "65816"
.segment "CODE"
.org $4505
map_control_0f4505:
    .byte $F1 ; progressive-copy count
    .byte $DA ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
