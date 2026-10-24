.setcpu "65816"
.segment "CODE"
.org $223E
map_control_0d223e:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
