.setcpu "65816"
.segment "CODE"
.org $0C5D
map_control_0d0c5d:
    .byte $E0 ; previous-row copy escape
    .byte $91 ; row-distance/count
