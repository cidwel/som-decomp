.setcpu "65816"
.segment "CODE"
.org $B4A8
map_control_0db4a8:
    .byte $E0 ; previous-row copy escape
    .byte $88 ; row-distance/count
