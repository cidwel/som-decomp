.setcpu "65816"
.segment "CODE"
.org $886F
map_control_0d886f:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
