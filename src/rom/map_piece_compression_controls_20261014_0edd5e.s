.setcpu "65816"
.segment "CODE"
.org $DD5E
map_control_0edd5e:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
