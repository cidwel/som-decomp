.setcpu "65816"
.segment "CODE"
.org $B92E
map_control_0fb92e:
    .byte $E0 ; previous-row copy escape
    .byte $33 ; row-distance/count
