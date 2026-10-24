.setcpu "65816"
.segment "CODE"
.org $F3B4
map_control_0df3b4:
    .byte $E0 ; previous-row copy escape
    .byte $88 ; row-distance/count
