.setcpu "65816"
.segment "CODE"
.org $EAA4
map_control_0deaa4:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
