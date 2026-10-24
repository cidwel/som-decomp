.setcpu "65816"
.segment "CODE"
.org $2AF1
map_control_0f2af1:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
