.setcpu "65816"
.segment "CODE"
.org $6CAD
map_control_0f6cad:
    .byte $F2 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $C3 ; row-distance/count
