.setcpu "65816"
.segment "CODE"
.org $2168
map_control_0f2168:
    .byte $E0 ; previous-row copy escape
    .byte $94 ; row-distance/count
    .byte $E1 ; previous-row copy count
