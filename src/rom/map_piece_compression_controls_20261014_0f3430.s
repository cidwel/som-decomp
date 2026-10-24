.setcpu "65816"
.segment "CODE"
.org $3430
map_control_0f3430:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
