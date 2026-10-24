.setcpu "65816"
.segment "CODE"
.org $CF41
map_control_0dcf41:
    .byte $E0 ; previous-row copy escape
    .byte $35 ; row-distance/count
