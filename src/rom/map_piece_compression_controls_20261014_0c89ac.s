.setcpu "65816"
.segment "CODE"
.org $89AC
map_control_0c89ac:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
