.setcpu "65816"
.segment "CODE"
.org $2B8B
map_control_0c2b8b:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
