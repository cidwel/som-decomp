.setcpu "65816"
.segment "CODE"
.org $FBD0
map_control_0ffbd0:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
