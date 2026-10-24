.setcpu "65816"
.segment "CODE"
.org $4B64
map_control_0d4b64:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
