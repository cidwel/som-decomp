.setcpu "65816"
.segment "CODE"
.org $99F0
map_control_0e99f0:
    .byte $E0 ; previous-row copy escape
    .byte $B7 ; row-distance/count
