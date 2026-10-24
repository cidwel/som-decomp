.setcpu "65816"
.segment "CODE"
.org $80AD
map_control_0d80ad:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
