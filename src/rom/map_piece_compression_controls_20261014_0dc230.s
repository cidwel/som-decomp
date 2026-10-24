.setcpu "65816"
.segment "CODE"
.org $C230
map_control_0dc230:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
