.setcpu "65816"
.segment "CODE"
.org $F559
map_control_0ef559:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $B4 ; row-distance/count
