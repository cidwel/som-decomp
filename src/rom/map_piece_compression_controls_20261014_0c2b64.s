.setcpu "65816"
.segment "CODE"
.org $2B64
map_control_0c2b64:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
