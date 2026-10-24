.setcpu "65816"
.segment "CODE"
.org $B10B
map_control_0eb10b:
    .byte $F1 ; progressive-copy count
    .byte $E2 ; previous-row copy count
    .byte $C5 ; same-value copy count/distance
