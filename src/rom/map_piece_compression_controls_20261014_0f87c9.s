.setcpu "65816"
.segment "CODE"
.org $87C9
map_control_0f87c9:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
