.setcpu "65816"
.segment "CODE"
.org $B862
map_control_0db862:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
