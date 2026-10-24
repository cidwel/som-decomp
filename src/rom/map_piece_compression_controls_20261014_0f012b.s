.setcpu "65816"
.segment "CODE"
.org $012B
map_control_0f012b:
    .byte $E0 ; previous-row copy escape
    .byte $88 ; row-distance/count
    .byte $E2 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
