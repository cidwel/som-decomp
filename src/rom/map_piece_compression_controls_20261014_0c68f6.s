.setcpu "65816"
.segment "CODE"
.org $68F6
map_control_0c68f6:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
