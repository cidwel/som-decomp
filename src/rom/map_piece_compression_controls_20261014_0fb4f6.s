.setcpu "65816"
.segment "CODE"
.org $B4F6
map_control_0fb4f6:
    .byte $E0 ; previous-row copy escape
    .byte $37 ; row-distance/count
