.setcpu "65816"
.segment "CODE"
.org $541E
map_control_0d541e:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
