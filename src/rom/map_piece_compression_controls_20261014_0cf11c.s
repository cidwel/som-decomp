.setcpu "65816"
.segment "CODE"
.org $F11C
map_control_0cf11c:
    .byte $E0 ; previous-row copy escape
    .byte $8E ; row-distance/count
    .byte $C1 ; same-value copy count/distance
