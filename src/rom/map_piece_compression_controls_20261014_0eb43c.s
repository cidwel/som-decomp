.setcpu "65816"
.segment "CODE"
.org $B43C
map_control_0eb43c:
    .byte $E0 ; previous-row copy escape
    .byte $90 ; row-distance/count
    .byte $E1 ; previous-row copy count
