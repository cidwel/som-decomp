.setcpu "65816"
.segment "CODE"
.org $B13E
map_control_0fb13e:
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
