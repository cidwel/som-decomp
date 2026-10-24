.setcpu "65816"
.segment "CODE"
.org $BF57
map_control_0fbf57:
    .byte $E0 ; previous-row copy escape
    .byte $2E ; row-distance/count
