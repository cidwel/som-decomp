.setcpu "65816"
.segment "CODE"
.org $9368
map_control_0f9368:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
