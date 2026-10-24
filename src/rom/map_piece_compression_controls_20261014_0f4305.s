.setcpu "65816"
.segment "CODE"
.org $4305
map_control_0f4305:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
