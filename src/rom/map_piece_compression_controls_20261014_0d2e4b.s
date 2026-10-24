.setcpu "65816"
.segment "CODE"
.org $2E4B
map_control_0d2e4b:
    .byte $E0 ; previous-row copy escape
    .byte $99 ; row-distance/count
