.setcpu "65816"
.segment "CODE"
.org $6B64
map_control_0e6b64:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
