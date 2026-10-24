.setcpu "65816"
.segment "CODE"
.org $747E
map_control_0d747e:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
