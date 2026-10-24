.setcpu "65816"
.segment "CODE"
.org $0F27
map_control_0d0f27:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
