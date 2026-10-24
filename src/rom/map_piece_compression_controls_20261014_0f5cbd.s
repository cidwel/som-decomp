.setcpu "65816"
.segment "CODE"
.org $5CBD
map_control_0f5cbd:
    .byte $E0 ; previous-row copy escape
    .byte $88 ; row-distance/count
