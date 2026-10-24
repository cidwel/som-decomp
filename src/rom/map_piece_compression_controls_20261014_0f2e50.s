.setcpu "65816"
.segment "CODE"
.org $2E50
map_control_0f2e50:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
