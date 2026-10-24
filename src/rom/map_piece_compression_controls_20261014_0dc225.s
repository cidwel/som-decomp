.setcpu "65816"
.segment "CODE"
.org $C225
map_control_0dc225:
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
