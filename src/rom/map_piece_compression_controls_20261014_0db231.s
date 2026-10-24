.setcpu "65816"
.segment "CODE"
.org $B231
map_control_0db231:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
