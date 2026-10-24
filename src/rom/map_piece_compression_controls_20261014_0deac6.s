.setcpu "65816"
.segment "CODE"
.org $EAC6
map_control_0deac6:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
