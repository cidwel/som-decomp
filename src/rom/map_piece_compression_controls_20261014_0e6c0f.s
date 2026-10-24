.setcpu "65816"
.segment "CODE"
.org $6C0F
map_control_0e6c0f:
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count
