.setcpu "65816"
.segment "CODE"
.org $6B9B
map_control_0f6b9b:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
