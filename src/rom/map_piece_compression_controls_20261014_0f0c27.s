.setcpu "65816"
.segment "CODE"
.org $0C27
map_control_0f0c27:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
