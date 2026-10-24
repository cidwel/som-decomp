.setcpu "65816"
.segment "CODE"
.org $7390
map_control_0d7390:
    .byte $E0 ; previous-row copy escape
    .byte $32 ; row-distance/count
