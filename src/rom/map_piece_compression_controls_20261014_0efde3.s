.setcpu "65816"
.segment "CODE"
.org $FDE3
map_control_0efde3:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
