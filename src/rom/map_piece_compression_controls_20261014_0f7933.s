.setcpu "65816"
.segment "CODE"
.org $7933
map_control_0f7933:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
