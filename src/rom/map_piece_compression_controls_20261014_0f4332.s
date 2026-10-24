.setcpu "65816"
.segment "CODE"
.org $4332
map_control_0f4332:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
