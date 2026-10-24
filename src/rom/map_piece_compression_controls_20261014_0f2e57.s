.setcpu "65816"
.segment "CODE"
.org $2E57
map_control_0f2e57:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
