.setcpu "65816"
.segment "CODE"
.org $CCC0
map_control_0eccc0:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
