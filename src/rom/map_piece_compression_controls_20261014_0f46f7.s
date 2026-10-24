.setcpu "65816"
.segment "CODE"
.org $46F7
map_control_0f46f7:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
