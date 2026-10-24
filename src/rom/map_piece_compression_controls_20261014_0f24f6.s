.setcpu "65816"
.segment "CODE"
.org $24F6
map_control_0f24f6:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
