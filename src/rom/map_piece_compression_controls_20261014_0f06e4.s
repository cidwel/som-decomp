.setcpu "65816"
.segment "CODE"
.org $06E4
map_control_0f06e4:
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
