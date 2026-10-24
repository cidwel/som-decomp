.setcpu "65816"
.segment "CODE"
.org $074C
map_control_0e074c:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
