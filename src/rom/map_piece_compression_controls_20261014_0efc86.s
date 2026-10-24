.setcpu "65816"
.segment "CODE"
.org $FC86
map_control_0efc86:
    .byte $E0 ; previous-row copy escape
    .byte $B7 ; row-distance/count
