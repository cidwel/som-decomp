.setcpu "65816"
.segment "CODE"
.org $DB89
map_control_0ddb89:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
