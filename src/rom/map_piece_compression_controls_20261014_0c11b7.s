.setcpu "65816"
.segment "CODE"
.org $11B7
map_control_0c11b7:
    .byte $E0 ; previous-row copy escape
    .byte $4F ; row-distance/count
