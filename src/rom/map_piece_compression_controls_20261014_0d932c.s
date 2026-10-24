.setcpu "65816"
.segment "CODE"
.org $932C
map_control_0d932c:
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
