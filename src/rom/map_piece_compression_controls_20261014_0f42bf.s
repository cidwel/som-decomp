.setcpu "65816"
.segment "CODE"
.org $42BF
map_control_0f42bf:
    .byte $E0 ; previous-row copy escape
    .byte $4E ; row-distance/count
