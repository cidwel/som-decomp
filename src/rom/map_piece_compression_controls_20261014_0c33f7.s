.setcpu "65816"
.segment "CODE"
.org $33F7
map_control_0c33f7:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
