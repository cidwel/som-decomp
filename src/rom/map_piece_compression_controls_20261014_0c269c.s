.setcpu "65816"
.segment "CODE"
.org $269C
map_control_0c269c:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
    .byte $C2 ; same-value copy count/distance
