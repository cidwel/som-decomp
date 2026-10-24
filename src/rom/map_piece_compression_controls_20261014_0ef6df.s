.setcpu "65816"
.segment "CODE"
.org $F6DF
map_control_0ef6df:
    .byte $E0 ; previous-row copy escape
    .byte $38 ; row-distance/count
