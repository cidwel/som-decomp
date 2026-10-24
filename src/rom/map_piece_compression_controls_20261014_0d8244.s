.setcpu "65816"
.segment "CODE"
.org $8244
map_control_0d8244:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
