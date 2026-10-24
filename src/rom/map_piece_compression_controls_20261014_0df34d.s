.setcpu "65816"
.segment "CODE"
.org $F34D
map_control_0df34d:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
