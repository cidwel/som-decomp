.setcpu "65816"
.segment "CODE"
.org $B991
map_control_0fb991:
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
