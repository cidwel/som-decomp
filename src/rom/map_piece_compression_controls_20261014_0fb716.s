.setcpu "65816"
.segment "CODE"
.org $B716
map_control_0fb716:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
