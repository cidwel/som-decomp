.setcpu "65816"
.segment "CODE"
.org $3AEE
map_control_0c3aee:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
