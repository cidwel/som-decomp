.setcpu "65816"
.segment "CODE"
.org $DE98
map_control_0dde98:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
