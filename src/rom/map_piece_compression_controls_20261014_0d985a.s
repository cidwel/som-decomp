.setcpu "65816"
.segment "CODE"
.org $985A
map_control_0d985a:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
