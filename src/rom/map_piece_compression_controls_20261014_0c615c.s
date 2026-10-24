.setcpu "65816"
.segment "CODE"
.org $615C
map_control_0c615c:
    .byte $DA ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $35 ; row-distance/count
