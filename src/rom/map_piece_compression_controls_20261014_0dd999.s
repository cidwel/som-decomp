.setcpu "65816"
.segment "CODE"
.org $D999
map_control_0dd999:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
