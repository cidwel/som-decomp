.setcpu "65816"
.segment "CODE"
.org $D284
map_control_0dd284:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
