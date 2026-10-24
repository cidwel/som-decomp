.setcpu "65816"
.segment "CODE"
.org $7933
map_control_0e7933:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
