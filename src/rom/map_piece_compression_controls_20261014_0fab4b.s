.setcpu "65816"
.segment "CODE"
.org $AB4B
map_control_0fab4b:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
