.setcpu "65816"
.segment "CODE"
.org $99F7
map_control_0e99f7:
    .byte $E0 ; previous-row copy escape
    .byte $B7 ; row-distance/count
