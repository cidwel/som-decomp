.setcpu "65816"
.segment "CODE"
.org $781E
map_control_0f781e:
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
