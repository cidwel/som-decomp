.setcpu "65816"
.segment "CODE"
.org $89DB
map_control_0d89db:
    .byte $E0 ; previous-row copy escape
    .byte $9C ; row-distance/count
