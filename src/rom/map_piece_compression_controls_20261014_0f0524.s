.setcpu "65816"
.segment "CODE"
.org $0524
map_control_0f0524:
    .byte $E5 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
