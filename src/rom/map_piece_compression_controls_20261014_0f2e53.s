.setcpu "65816"
.segment "CODE"
.org $2E53
map_control_0f2e53:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
