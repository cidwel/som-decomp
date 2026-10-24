.setcpu "65816"
.segment "CODE"
.org $06F1
map_control_0f06f1:
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
