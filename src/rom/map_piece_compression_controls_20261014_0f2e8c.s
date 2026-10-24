.setcpu "65816"
.segment "CODE"
.org $2E8C
map_control_0f2e8c:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
