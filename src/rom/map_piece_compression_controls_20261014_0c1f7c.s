.setcpu "65816"
.segment "CODE"
.org $1F7C
map_control_0c1f7c:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
