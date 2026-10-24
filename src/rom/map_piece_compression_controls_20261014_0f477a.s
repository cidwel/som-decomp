.setcpu "65816"
.segment "CODE"
.org $477A
map_control_0f477a:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
