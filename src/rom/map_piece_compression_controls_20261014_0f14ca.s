.setcpu "65816"
.segment "CODE"
.org $14CA
map_control_0f14ca:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
