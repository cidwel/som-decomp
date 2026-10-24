.setcpu "65816"
.segment "CODE"
.org $596A
map_control_0f596a:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
