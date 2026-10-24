.setcpu "65816"
.segment "CODE"
.org $9C4A
map_control_0e9c4a:
    .byte $E0 ; previous-row copy escape
    .byte $33 ; row-distance/count
