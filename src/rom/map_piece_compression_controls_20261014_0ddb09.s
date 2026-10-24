.setcpu "65816"
.segment "CODE"
.org $DB09
map_control_0ddb09:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
