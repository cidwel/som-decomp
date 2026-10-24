.setcpu "65816"
.segment "CODE"
.org $8879
map_control_0f8879:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
