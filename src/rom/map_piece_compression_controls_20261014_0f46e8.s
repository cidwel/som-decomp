.setcpu "65816"
.segment "CODE"
.org $46E8
map_control_0f46e8:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
