.setcpu "65816"
.segment "CODE"
.org $1DCF
map_control_0d1dcf:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $D3 ; same-value copy count/distance
