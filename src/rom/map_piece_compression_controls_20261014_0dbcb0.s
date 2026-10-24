.setcpu "65816"
.segment "CODE"
.org $BCB0
map_control_0dbcb0:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
