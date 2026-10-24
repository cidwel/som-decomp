.setcpu "65816"
.segment "CODE"
.org $8A61
map_control_0f8a61:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
