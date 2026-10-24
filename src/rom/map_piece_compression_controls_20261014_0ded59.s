.setcpu "65816"
.segment "CODE"
.org $ED59
map_control_0ded59:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
