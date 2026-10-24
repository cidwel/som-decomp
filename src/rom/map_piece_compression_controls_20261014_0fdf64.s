.setcpu "65816"
.segment "CODE"
.org $DF64
map_control_0fdf64:
    .byte $C9 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $9C ; row-distance/count
    .byte $E2 ; previous-row copy count
