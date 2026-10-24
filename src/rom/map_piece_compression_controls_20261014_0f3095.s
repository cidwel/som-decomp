.setcpu "65816"
.segment "CODE"
.org $3095
map_control_0f3095:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
