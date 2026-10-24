.setcpu "65816"
.segment "CODE"
.org $B97C
map_control_0db97c:
    .byte $C9 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
