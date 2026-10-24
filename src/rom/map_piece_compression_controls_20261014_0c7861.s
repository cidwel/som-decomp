.setcpu "65816"
.segment "CODE"
.org $7861
map_control_0c7861:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
