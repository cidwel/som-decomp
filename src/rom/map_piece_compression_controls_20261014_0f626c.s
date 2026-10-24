.setcpu "65816"
.segment "CODE"
.org $626C
map_control_0f626c:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
