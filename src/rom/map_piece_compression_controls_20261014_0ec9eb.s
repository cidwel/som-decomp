.setcpu "65816"
.segment "CODE"
.org $C9EB
map_control_0ec9eb:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
