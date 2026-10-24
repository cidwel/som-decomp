.setcpu "65816"
.segment "CODE"
.org $C34F
map_control_0dc34f:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
