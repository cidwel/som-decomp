.setcpu "65816"
.segment "CODE"
.org $7942
map_control_0f7942:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
