.setcpu "65816"
.segment "CODE"
.org $0FEF
map_control_0f0fef:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
