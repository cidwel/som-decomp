.setcpu "65816"
.segment "CODE"
.org $B09D
map_control_0eb09d:
    .byte $F1 ; progressive-copy count
    .byte $E1 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
