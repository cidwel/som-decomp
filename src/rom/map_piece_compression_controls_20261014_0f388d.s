.setcpu "65816"
.segment "CODE"
.org $388D
map_control_0f388d:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
