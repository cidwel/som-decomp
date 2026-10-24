.setcpu "65816"
.segment "CODE"
.org $CC39
map_control_0fcc39:
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $56 ; row-distance/count
