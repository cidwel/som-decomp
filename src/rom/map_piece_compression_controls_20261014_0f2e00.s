.setcpu "65816"
.segment "CODE"
.org $2E00
map_control_0f2e00:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
