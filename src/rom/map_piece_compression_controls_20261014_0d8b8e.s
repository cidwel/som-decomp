.setcpu "65816"
.segment "CODE"
.org $8B8E
map_control_0d8b8e:
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $8E ; row-distance/count
