.setcpu "65816"
.segment "CODE"
.org $FA1B
map_control_0efa1b:
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
