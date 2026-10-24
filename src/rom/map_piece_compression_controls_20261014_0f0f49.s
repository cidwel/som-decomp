.setcpu "65816"
.segment "CODE"
.org $0F49
map_control_0f0f49:
    .byte $E0 ; previous-row copy escape
    .byte $2E ; row-distance/count
