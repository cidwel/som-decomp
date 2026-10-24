.setcpu "65816"
.segment "CODE"
.org $36FD
map_control_0f36fd:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
