.setcpu "65816"
.segment "CODE"
.org $66C1
map_control_0d66c1:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
