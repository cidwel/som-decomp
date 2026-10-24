.setcpu "65816"
.segment "CODE"
.org $D2E4
map_control_0ed2e4:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
