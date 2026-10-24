.setcpu "65816"
.segment "CODE"
.org $DF7C
map_control_0fdf7c:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
