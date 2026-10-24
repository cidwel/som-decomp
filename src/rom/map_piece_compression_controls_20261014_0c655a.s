.setcpu "65816"
.segment "CODE"
.org $655A
map_control_0c655a:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
