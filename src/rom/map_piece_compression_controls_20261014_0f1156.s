.setcpu "65816"
.segment "CODE"
.org $1156
map_control_0f1156:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
