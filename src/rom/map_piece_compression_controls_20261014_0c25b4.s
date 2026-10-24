.setcpu "65816"
.segment "CODE"
.org $25B4
map_control_0c25b4:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
