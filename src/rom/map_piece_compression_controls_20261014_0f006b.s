.setcpu "65816"
.segment "CODE"
.org $006B
map_control_0f006b:
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
    .byte $E4 ; previous-row copy count
