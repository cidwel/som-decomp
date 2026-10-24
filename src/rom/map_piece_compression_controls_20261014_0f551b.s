.setcpu "65816"
.segment "CODE"
.org $551B
map_control_0f551b:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
