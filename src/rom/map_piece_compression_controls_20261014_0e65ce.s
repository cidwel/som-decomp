.setcpu "65816"
.segment "CODE"
.org $65CE
map_control_0e65ce:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
