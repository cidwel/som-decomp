.setcpu "65816"
.segment "CODE"
.org $16DF
map_control_0e16df:
    .byte $E0 ; previous-row copy escape
    .byte $B5 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $37 ; row-distance/count
