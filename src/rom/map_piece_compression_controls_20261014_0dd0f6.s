.setcpu "65816"
.segment "CODE"
.org $D0F6
map_control_0dd0f6:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
