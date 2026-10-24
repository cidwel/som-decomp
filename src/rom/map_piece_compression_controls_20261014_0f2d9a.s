.setcpu "65816"
.segment "CODE"
.org $2D9A
map_control_0f2d9a:
    .byte $E0 ; previous-row copy escape
    .byte $2E ; row-distance/count
