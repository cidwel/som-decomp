.setcpu "65816"
.segment "CODE"
.org $F2BF
map_control_0df2bf:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
