.setcpu "65816"
.segment "CODE"
.org $CF57
map_control_0dcf57:
    .byte $E0 ; previous-row copy escape
    .byte $33 ; row-distance/count
