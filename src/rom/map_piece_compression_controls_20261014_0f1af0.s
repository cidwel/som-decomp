.setcpu "65816"
.segment "CODE"
.org $1AF0
map_control_0f1af0:
    .byte $E0 ; previous-row copy escape
    .byte $2B ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $B4 ; row-distance/count
