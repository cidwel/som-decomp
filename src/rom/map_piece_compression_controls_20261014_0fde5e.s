.setcpu "65816"
.segment "CODE"
.org $DE5E
map_control_0fde5e:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
