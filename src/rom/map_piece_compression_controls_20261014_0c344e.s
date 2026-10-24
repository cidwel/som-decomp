.setcpu "65816"
.segment "CODE"
.org $344E
map_control_0c344e:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
