.setcpu "65816"
.segment "CODE"
.org $F54B
map_control_0ff54b:
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $38 ; row-distance/count
