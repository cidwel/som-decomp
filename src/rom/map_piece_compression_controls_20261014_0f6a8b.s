.setcpu "65816"
.segment "CODE"
.org $6A8B
map_control_0f6a8b:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
