.setcpu "65816"
.segment "CODE"
.org $AA34
map_control_0faa34:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
