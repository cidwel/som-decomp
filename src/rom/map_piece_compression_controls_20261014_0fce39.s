.setcpu "65816"
.segment "CODE"
.org $CE39
map_control_0fce39:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
