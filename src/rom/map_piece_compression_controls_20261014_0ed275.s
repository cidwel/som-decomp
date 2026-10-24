.setcpu "65816"
.segment "CODE"
.org $D275
map_control_0ed275:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
