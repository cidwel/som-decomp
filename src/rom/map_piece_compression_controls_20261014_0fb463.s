.setcpu "65816"
.segment "CODE"
.org $B463
map_control_0fb463:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
