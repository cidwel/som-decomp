.setcpu "65816"
.segment "CODE"
.org $6912
map_control_0d6912:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
