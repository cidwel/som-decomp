.setcpu "65816"
.segment "CODE"
.org $292B
map_control_0d292b:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
