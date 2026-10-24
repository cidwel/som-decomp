.setcpu "65816"
.segment "CODE"
.org $BF3B
map_control_0dbf3b:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
