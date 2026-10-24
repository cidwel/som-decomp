.setcpu "65816"
.segment "CODE"
.org $2248
map_control_0d2248:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
