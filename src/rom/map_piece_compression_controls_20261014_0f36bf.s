.setcpu "65816"
.segment "CODE"
.org $36BF
map_control_0f36bf:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
