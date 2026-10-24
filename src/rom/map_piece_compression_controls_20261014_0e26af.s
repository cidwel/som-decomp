.setcpu "65816"
.segment "CODE"
.org $26AF
map_control_0e26af:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
